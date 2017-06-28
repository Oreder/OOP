#include "stdafx.h"
#include "transform_point.h"

ACTION_RET Shift_One_Point (Coord &point, Param_Shift shift)
{
	if (&point == nullptr)
		return NO_DATA;

	point.x += shift.dx;
	point.y += shift.dy;
	point.z += shift.dz;

	return SUCCESS_ACT;
}

ACTION_RET Scale_One_Point (Coord &point, Param_Scale scale)
{
	if (&point == nullptr)
		return NO_DATA;

	point.x *= scale.kx;
	point.y *= scale.ky;
	point.z *= scale.kz;

	return SUCCESS_ACT;
}

ACTION_RET Rotate_One_Point (Coord &point, Param_Rotate rotate)
{
	if (&point == nullptr)
		return NO_DATA;

	double y = point.y;
	point.y = point.y * cos(rotate.ox) - point.z * sin(rotate.ox);
	point.z = y * sin(rotate.ox) + point.z * cos(rotate.ox);

	double x = point.x;
	point.x = point.x * cos(rotate.oy) + point.z * sin(rotate.oy);
	point.z = -x * sin(rotate.oy) + point.z * cos(rotate.oy);

	x = point.x;
	point.x = point.x * cos(rotate.oz) - point.y * sin(rotate.oz);
	point.y = x * sin(rotate.oz) + point.y * cos(rotate.oz);

	return SUCCESS_ACT;
}