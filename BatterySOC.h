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

#define STEPV    (uint16_t)100
#define STEPT    (index_t)1

typedef uint16_t  Vcell_t;
typedef int16_t   temperature_t;
typedef uint8_t  soc_t;
typedef uint8_t  index_t;


extern uint16_t TableSocVirtual[];
extern int16_t TrangeTbl[]; 

int16_t interpolate(int16_t key, int16_t verticalLow, int16_t verticalHigh, int16_t horizonLow, int16_t horizonHigh);
//void  buildVirtualTable(temperature_t temperature, temperature_t rangeTbl[], index_t idxT, Vcell_t Tn_Tbl[], index_t lenVirtualTbl);
void buildVirtualTable(temperature_t Tamb, temperature_t rangeTbl[], index_t indexT, Vcell_t virtualSocTbl[][2], index_t lenVirtualTbl);
index_t getIndex(int16_t key, int16_t tbl[], index_t lenTbl);
soc_t getSOC(Vcell_t Vcell, temperature_t Tamb, soc_t curSoc);
//double interp_table(double dbl_table[][2], int col_a);
int16_t interp_table(Vcell_t 	dbl_table[][2], Vcell_t col_a);