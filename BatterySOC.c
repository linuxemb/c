#include <stdint.h>
#include <stdbool.h>
#include <stdio.h> // suppor fprintf
#include "BatterySOC.h"


#define ROWSSOCTBL 21
#define NewChem  0

extern int16_t TableSOC[ROWSSOCTBL][COLSSOCTBL];
//extern int16_t TableSOCOld[ROWSSOCTBL][COLSSOCTBL];
extern int16_t  virtualTblSOC[ROWSSOCTBL][2];
extern uint16_t  TblSOCOldChem[][2];


uint16_t TableSocVirtual[ROWSSOCTBL];
int16_t TrangeTbl[COLSRANGETBL] = { -40, -18, 25, 55 };

int16_t TrangeTblOld[COLSRANGETBLOLD] = { -40, 24 }; 

// Retrieve soc value based on ambient temperature , cell voltage and  current SOC
soc_t getSOC( Vcell_t Vcell, temperature_t Tamb, soc_t curSoc)
{
	index_t idxT, idxV;
	index_t soc = curSoc;
	idxT = 0;
		
	if (NewChem)
	{
		idxT = getIndex(Tamb, TrangeTbl, COLSRANGETBL);
	}
		if (idxT) {

			buildVirtualTable(Tamb, TrangeTbl, idxT, &TableSocVirtual[0], ROWSSOCTBL);
		}
	
	else  // build virtualtabl for old chemistry
	{
		buildVirtualTable(Tamb, TrangeTblOld, idxT, &TableSocVirtual[0], ROWSSOCTBL);
	}
		soc = interpTable(virtualTblSOC, Vcell);  
		
	return(soc);
}

// Generate virtual Table for Vcell and SOC col 0-> vcell, col1->soc
void  buildVirtualTable(temperature_t Tamb, temperature_t rangeTbl[], index_t indexT, Vcell_t virtualSocTbl[][2], index_t lenVirtualTbl)
{
	
	temperature_t tLow, tHigh;
	Vcell_t   vLow, vHigh;
	index_t i;
	for (i = 0; i<lenVirtualTbl; i++) {
		// Add case for old chemistry table
		if (NewChem)
		{
			tLow = rangeTbl[indexT - 1];  // temperatrue
			tHigh = rangeTbl[indexT];
			vLow = TableSOC[i][indexT];  //
			vHigh = TableSOC[i][indexT + 1];
			//virtualSocTbl[i] = interpolate(Tamb, tLow, tHigh, vLow, vHigh);
			virtualTblSOC[i][0] = interpRange(Tamb, tLow, tHigh, vLow, vHigh);  // Vcell
		}
		else
		{
			// Copy over old chemistry soc table Voltage
			virtualTblSOC[i][0] = TblSOCOldChem[i][0];
		}
	}
}

// 2 dimenstion table lookup and interpolation
/*
*  interpolation function by range: between xlow, xhigh and vlow vhigh
* should return linear interpolated second dimension value
* if the col_a value is greater it will return the highest value(capped results)
* results off the lower end of the chart will interpolate to zero
*/

int16_t interpRange(int16_t key, int16_t yLow, int16_t yHigh, int16_t xLow, int16_t xhigh)
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

// Used to retrieve the range of index of Temperature in Trange table
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



// One demension table introplate...
/**
*  interpolation function
* should return linear interpolated second dimension value
* if the vCelll is greater it will return the highest value (capped results)
* results off the lower end of the chart will interpolate to zero
*/



int16_t interpTable(Vcell_t virtualTbl[][2], Vcell_t vCell)
{
	index_t i;
	double deltaV;

	for (i = 0; virtualTbl[i][0]; i++) {
		if ((virtualTbl[i][0] <= vCell) && (virtualTbl[i + 1][0] >= vCell)) {
			deltaV = virtualTbl[i][1] - virtualTbl[i + 1][1];
			return  (int16_t)virtualTbl[i + 1][1] + (int16_t)(deltaV *(vCell - virtualTbl[i + 1][0]) / (virtualTbl[i][0] - virtualTbl[i + 1][0]));
		}
	}

	if (vCell > virtualTbl[0][0]) {
		return virtualTbl[ROWSSOCTBL -1][1];
	}

	return 0;
}
