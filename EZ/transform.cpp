#include "stdafx.h"
#include "transform.h"

ACTION_RET Scale_Model(Figure_Param &figure, Param_Scale scale)
{
	if (&figure == nullptr)
		return NO_DATA;

	return Scale_Points (figure.s_points, scale);
}

ACTION_RET Rotate_Model(Figure_Param &figure, Param_Rotate rotate)
{
	if (&figure == nullptr)
		return NO_DATA;

	return Rotate_Points (figure.s_points, rotate);
}


ACTION_RET Shift_Model(Figure_Param &figure, Param_Shift shift)
{
	if (&figure == nullptr)
		return NO_DATA;

	return Shift_Points (figure.s_points, shift);
}