#include "stdafx.h"
#include "transform_point_arr.h"

void Convert_Angles (Param_Rotate &rotate)
{
	rotate.ox *= M_PI / 180;
	rotate.oy *= M_PI / 180;
	rotate.oz *= M_PI / 180;
}

ACTION_RET Shift_Points (M_Points &points, Param_Shift shift)
{
	if (&points == nullptr)
		return NO_DATA;

	ACTION_RET res = SUCCESS_ACT;

	for (int i = 0; i < points.Np && res == SUCCESS_ACT; i++)
		res = Shift_One_Point(points.pnt[i], shift);

	return res;
}

ACTION_RET Scale_Points (M_Points &points, Param_Scale scale)
{
	if (&points == nullptr)
		return NO_DATA;

	ACTION_RET res = SUCCESS_ACT;

	for (int i = 0; i < points.Np && res == SUCCESS_ACT; i++)
		res = Scale_One_Point(points.pnt[i], scale);

	return res;
}

ACTION_RET Rotate_Points (M_Points &points, Param_Rotate rotate)
{
	if (&points == nullptr)
		return NO_DATA;

	Convert_Angles(rotate);

	ACTION_RET res = SUCCESS_ACT;

	for (int i = 0; i < points.Np && res == SUCCESS_ACT; i++)
		res = Rotate_One_Point(points.pnt[i], rotate);

	return res;
}