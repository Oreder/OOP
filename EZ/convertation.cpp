#include "stdafx.h"
#include "convertation.h"


ACTION_RET Find_Zoom(M_Points arr, Scr_Arr scr, Canvas_Param cur_canvas)
{
	if (arr.pnt == nullptr)
		return NO_DATA;

	if (scr.point == nullptr)
		return FATAL_ERROR;

	ACTION_RET res = SUCCESS_ACT;

	double zoom = Find_Max(arr);
	for (int i = 0; i < arr.Np && res == SUCCESS_ACT; i++)
	{		
		res = Convert_Point(scr.point[i], arr.pnt[i], cur_canvas, zoom);
	}	

	return res;
}

ACTION_RET Convert_Point(Scr_Pnt &out, Coord in, Canvas_Param cur_canvas, double zoom)
{
	if (&out == nullptr)
		return NO_DATA;

	double zf = abs(4 * zoom);
	double zp = abs(2 * zoom);
	double f = zf - zp;
	out.X = (int)(f * in.x / (zf - in.z) + cur_canvas.cx);
	out.Y = (int)(cur_canvas.cy - f * in.y / (zf - in.z));

	return SUCCESS_ACT;
}

double Compare_Num (Coord point, double num)
{
	return point.z - num;
}

double Assign_Num (Coord point)
{
	return point.z;
}

double Find_Max (M_Points arr)
{
	double max = Assign_Num(arr.pnt[0]);
	for (int i = 0; i < arr.Np; i++)
	{
		if (Compare_Num(arr.pnt[i], max) > 0)
			max = Assign_Num(arr.pnt[i]);
	}

	return max;
}