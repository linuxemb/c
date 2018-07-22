#pragma once


#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "BatteryUser.h"


#define ROWSSOCTBL        21
#define COLSSOCTBL	      5
#define COLSRANGETBL      4
#define COLSRANGETBLOLD   2
#define STEPV    (uint16_t)100
#define STEPT    (index_t)1

typedef uint16_t  Vcell_t;
typedef int16_t   temperature_t;
typedef uint8_t  soc_t;
typedef uint8_t  index_t;


extern uint16_t TableSocVirtual[];
extern int16_t TrangeTbl[]; 


/* 2 dimenstion table lookup and interpolation 
 * interpolation function by range: between xlow, xhigh and vlow vhigh
* should return linear interpolated second dimension value
* if the col_a value is greater it will return the highest value(capped results)
* results off the lower end of the chart will interpolate to zero
*/
int16_t interpRange(int16_t key, int16_t verticalLow, int16_t verticalHigh, int16_t horizonLow, int16_t horizonHigh);

// Generate virtual Table for Vcell and SOC col 0-> vcell, col1->soc
void buildVirtualTable(temperature_t Tamb, temperature_t rangeTbl[], index_t indexT, Vcell_t virtualSocTbl[][2], index_t lenVirtualTbl);

// Used to retrieve the range of index of Temperature in Trange table
index_t getIndex(int16_t key, int16_t tbl[], index_t lenTbl);

// Retrieve soc value based on ambient temperature , cell voltage and  current SOC
soc_t getSOC(Vcell_t Vcell, temperature_t Tamb, soc_t curSoc);


/*One demension table introplate...
*  interpolation function
* should return linear interpolated second dimension value
* if the vCelll is greater it will return the highest value (capped results)
* results off the lower end of the chart will interpolate to zero
*/

int16_t interpTable(Vcell_t 	dbl_table[][2], Vcell_t col_a);