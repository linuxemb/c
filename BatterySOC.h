#pragma once


#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "BatteryUser.h"


#define rowsSocTable      21
#define colsSocTable	   5
#define colsRangeTable     4
//#define colsSocTableOld    3
//#define colsRangeTableOld  2

#define stepV    (uint16_t)100
#define stepT    (index_t)1

typedef uint16_t  Vcell_t;
typedef int16_t   temperature_t;
typedef uint8_t  soc_t;
typedef uint8_t  index_t;


extern uint16_t TableSocVirtual[];
extern int16_t TrangeTbl[]; 

int16_t interpolate(int16_t key, int16_t verticalLow, int16_t verticalHigh, int16_t horizonLow, int16_t horizonHigh);
void  buildVirtualTable(temperature_t temperature, temperature_t rangeTbl[], index_t idxT, Vcell_t Tn_Tbl[], index_t lenVirtualTbl);
index_t getIndex(int16_t key, int16_t tbl[], index_t lenTbl);
soc_t getSOC(Vcell_t Vcell, temperature_t Tamb, soc_t curSoc);