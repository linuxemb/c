#pragma once


//BatteryUser.c
#include <stdint.h>
#include <stdbool.h>
#include "BatteryUser.h"



#define COLSSOCTBL	5
#define COLSRANGETBL  4
#define ROWSSOCTBL   21
#define colsSocTableOld 3

const uint16_t TableSOC[ROWSSOCTBL][COLSSOCTBL] =

//soc  -40   -18   25   55
{
{ 0, 3456, 3380, 3300, 2500 },
{ 5, 3457, 3407, 3357, 2557 },
{ 10, 3458, 3446, 3412, 3267 },
{ 15, 3460, 3479, 3438, 3405 },
{ 20, 3462, 3509, 3481, 3431 },
{ 25, 3462, 3533, 3518, 3473 },
{ 30, 3462, 3554, 3547, 3512 },
{ 35, 3477, 3572, 3574, 3542 },
{ 40, 3502, 3588, 3593, 3571 },
{ 45, 3523, 3604, 3608, 3602 },
{ 50, 3545, 3619, 3622, 3618 },
{ 55, 3566, 3637, 3639, 3633 },
{ 60, 3588, 3661, 3658, 3651 },
{ 65, 3614, 3691, 3684, 3675 },
{ 70, 3644, 3728, 3719, 3705 },
{ 75, 3679, 3772, 3777, 3753 },
{ 80, 3720, 3821, 3825, 3812 },
{ 85, 3767, 3869, 3868, 3859 },
{ 90, 3818, 3912, 3913, 3906 },
{ 95, 3871, 3956, 3960, 3952 },
{ 100, 3933, 3904, 4020,3999 }
};

//const uint16_t TableSOCOld[ROWSSOCTBL][COLSSOCTBL] =
//
//{
//	//  %  mV@-40C mV@24C
//	{ 0,   3400,2857, 2857, 2857, },
//	{ 5,  3442 , 3346,3346,3346,  },
//	{ 10,  3475,3439,3439,3439,   },
//	{ 15,  3506 ,3473, 3473,3473, },
//	{ 20,  3537 ,3514, 3514, 3514,},
//	{ 25,  3569, 3549 ,3549, 3549,},
//	{ 30,  3604,3580 ,3580, 3580, },
//	{ 35,  3645, 3610,3610, 3610, },
//	{ 40,  3690, 3636, 3636, 3636,},
//	{ 45,  3739, 3663,3663,3663, },
//	{ 50,  3789,3700,3700,3700,  },
//	{ 55,  3839,3747,3747,3747,  },
//	{ 60,  3891,3747,3747,3747,  },
//	{ 65,  3945, 3846,3846,3846, },
//	{ 70,  4003, 3902, 3902, 3902,},
//	{ 75,  4070, 3951,3951,3951, },
//	{ 80,  4136, 3994,3994,3994, },
//	{ 85,  4202, 4037,4037,4037, },
//	{ 90,  4269, 4076,4076,4076, },
//	{ 95,  4335, 4123,4123,4123, },
//	{ 100, 4402, 4185,4185,4185, },
//};
uint16_t  virtualTblSOC[][2] =
{
	//  %  mV@24C mV@-40C
	{  0,  0,},
	{  0,  5,},
	{ 0,  10,},
	{  0,  15,},
	{ 0,  20, },
	{ 0,  25,},
	{ 0, 30, },
	{ 0,   35, },
	{ 0,  40, },
	{ 0, 45, },
	{ 0,  50, },
	{ 0,  55, },
	{ 0, 60, },
	{ 0, 65, },
	{ 0, 70, },
	{ 0,  75, },
	{ 0, 80, },
	{ 0, 85, },
	{ 0, 90, },
	{ 0,  95, },
	{ 0, 100, },
};
uint16_t  TblSOCOldChem[][2] =
{
	//  %  mV@24C mV@-40C
	{ 2857,  0, },
	{ 3346,  5, },
	{ 3439,  10, },
	{ 3473,  15, },
	{ 3514,  20, },
	{ 3549,  25, },
	{ 3580,  30, },
	{ 3610,  35, },
	{ 3636,  40, },
	{ 3663,  45, },
	{ 3700,  50, },
	{ 3747,  55, },
	{ 3797,  60, },
	{ 3846,  65, },
	{ 3902,  70, },
	{ 3951,  75, },
	{ 3994,  80, },
	{ 4037,  85, },
	{ 4076,  90, },
	{ 4123,  95, },
	{ 4185,  100, },
};