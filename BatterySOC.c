#include <stdint.h>
#include <stdbool.h>
#include <stdio.h> // suppor fprintf
#include "BatterySOC.h"

extern int16_t TableSOC[ROWSSOCTBL][COLSSOCTBL];
extern int16_t TableSOCOld[ROWSSOCTBL][COLSSOCTBL];
extern int16_t  vtSOC[ROWSSOCTBL][2];
#define ROWSSOCTBL 21
uint16_t TableSocVirtual[ROWSSOCTBL];
int16_t TrangeTbl[COLSRANGETBL] = { -40, -18, 25, 55 };


int16_t TrangeTblOld[COLSRANGETBL] = { -40, 24, 24, 24 };

soc_t getSOC( Vcell_t Vcell, temperature_t Tamb, soc_t curSoc)
{
	index_t idxT, idxV;
	index_t soc = curSoc;
	
	// if old chemistry, just need interplate once


	idxT = getIndex(Tamb, TrangeTbl, COLSRANGETBL );
	if (idxT) {

		//buildVirtualTable(Tamb, TrangeTbl, idxT, &TableSocVirtual[0], ROWSSOCTBL);
		buildVirtualTable(Tamb, TrangeTbl, idxT, TableSocVirtual, ROWSSOCTBL);
		soc = interp_table(vtSOC, Vcell);
		
		idxV = getIndex(Vcell, TableSocVirtual, ROWSSOCTBL); // old version
	 	
		if (idxV) {
			
			soc = interpolate(Vcell, TableSocVirtual[idxV - 1], TableSocVirtual[idxV], TableSOCOld[idxV - 1][0], TableSOCOld[idxV][0]);
		}
	}
	return(soc);
}


//void  buildVirtualTable(temperature_t Tamb, temperature_t rangeTbl[], index_t indexT, Vcell_t virtualSocTbl[], index_t lenVirtualTbl) //

void  buildVirtualTable(temperature_t Tamb, temperature_t rangeTbl[], index_t indexT, Vcell_t virtualSocTbl[][2], index_t lenVirtualTbl)
{
	
	temperature_t tLow, tHigh;
	Vcell_t   vLow, vHigh;
	index_t i;
	for (i = 0; i<lenVirtualTbl; i++) {
		tLow = rangeTbl[indexT - 1];  // temperatrue
		tHigh = rangeTbl[indexT];      
		vLow = TableSOC[i][indexT ];  //
		vHigh = TableSOC[i][indexT+1];
		//virtualSocTbl[i] = interpolate(Tamb, tLow, tHigh, vLow, vHigh);
		vtSOC[i][0] = interpolate(Tamb, tLow, tHigh, vLow, vHigh);  // Vcell
	}
}

// 2 dimenstion table lookup and intreplate

int16_t interpolate(int16_t key, int16_t yLow, int16_t yHigh, int16_t xLow, int16_t xhigh)
{
    int16_t x_delta, val;
	float m, y_num, y_denom;
	int16_t retval;
	y_num = (key - yLow);
	y_denom = (yHigh - yLow);
	m = y_num / y_denom;
	x_delta = xhigh - xLow;
	val = m * x_delta;
	retval = (int16_t)val + xLow;
	return(retval);
}



index_t getIndex(int16_t key, int16_t tbl[], index_t lenTbl)
{
	uint16_t retval = 0;
	index_t i;
	int tep = tbl[0];

	if ((key >= tbl[0]) && (key <= tbl[lenTbl - 1])) {
		for ( i = 1; i<lenTbl; i++) {
			if (key <= tbl[i]) {
				retval = i;
				break;
			}
		}
	}
	return(retval);
}




/**
* My interpolation function
* should return linear interpolated second dimension value
* if the col_a value is greater it will return the highest value (capped results)
* results off the lower end of the chart will interpolate to zero
*/

// One demension table introplate...

int16_t interp_table(Vcell_t 	dbl_table[][2], Vcell_t col_a)
{
	short i;
	double col_b_diff;

	for (i = 0; dbl_table[i][0]; i++) {
		if ((dbl_table[i][0] <= col_a) && (dbl_table[i + 1][0] >= col_a)) {
			col_b_diff = dbl_table[i][1] - dbl_table[i + 1][1];
			return  (int16_t)dbl_table[i + 1][1] + (int16_t)(col_b_diff *(col_a - dbl_table[i + 1][0]) / (dbl_table[i][0] - dbl_table[i + 1][0]));
		}
	}

	if (col_a > dbl_table[0][0]) {
		return dbl_table[0][1];
	}

	return 0;
}
