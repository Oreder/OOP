#pragma once
#define _USE_MATH_DEFINES
#include "math.h"
#include "transform_point.h"

ACTION_RET Shift_Points (M_Points &points, Param_Shift shift);
ACTION_RET Scale_Points (M_Points &points, Param_Scale scale);
ACTION_RET Rotate_Points (M_Points &points, Param_Rotate rotate);
void Convert_Angles (Param_Rotate &rotate);