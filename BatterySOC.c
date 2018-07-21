#include <stdint.h>
#include <stdbool.h>
#include <stdio.h> // suppor fprintf
#include "BatterySOC.h"

extern int16_t TableSOC[rowsSocTable][colsSocTable];
extern int16_t TableSOCOld[rowsSocTable][colsSocTable];

#define rowsSocTable 21
uint16_t TableSocVirtual[rowsSocTable];
int16_t TrangeTbl[colsRangeTable] = { -40, -18, 25, 55 };


int16_t TrangeTblOld[colsRangeTable] = { -40, 24, 24, 24 };

soc_t getSOC( Vcell_t Vcell, temperature_t Tamb, soc_t curSoc)
{
	index_t idxT, idxV;
	index_t soc = curSoc;
	
	
	int tep = TrangeTbl[0];
	

	idxT = getIndex(Tamb, TrangeTbl, colsRangeTable );
	if (idxT) {

		buildVirtualTable(Tamb, TrangeTbl, idxT, &TableSocVirtual[0], rowsSocTable);
		idxV = getIndex(Vcell, TableSocVirtual, rowsSocTable);
	 	
		if (idxV) {
			soc = interpolate(Vcell, TableSocVirtual[idxV - 1], TableSocVirtual[idxV], TableSOC[idxV - 1][0], TableSOC[idxV][0]);
			//soc = interpolate(Vcell, TableSocVirtual[idxV - 1], TableSocVirtual[idxV], TableSOCOld[idxV - 1][0], TableSOCOld[idxV][0]);
		}
	}
	return(soc);
}


void  buildVirtualTable(temperature_t Tamb, temperature_t rangeTbl[], index_t indexT, Vcell_t virtualSocTbl[], index_t lenVirtualTbl)
{
	
	temperature_t tLow, tHigh;
	Vcell_t   vLow, vHigh;
	index_t i;
	for (i = 0; i<lenVirtualTbl; i++) {
		tLow = rangeTbl[indexT - 1];  // temperatrue
		tHigh = rangeTbl[indexT];      
		vLow = TableSOC[i][indexT ];  //
		vHigh = TableSOC[i][indexT+1];
		virtualSocTbl[i] = interpolate(Tamb, tLow, tHigh, vLow, vHigh);
	}
}

int16_t interpolate(int16_t key, int16_t verticalL, int16_t verticalH, int16_t horizonL, int16_t horizonH)
{
    int16_t x_delta, val;
	float m, y_num, y_denom;
	int16_t retval;
	y_num = (key - verticalL);
	y_denom = (verticalH - verticalL);
	m = y_num / y_denom;
	x_delta = horizonH - horizonL;
	val = m * x_delta;
	retval = (int16_t)val + horizonL;
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




