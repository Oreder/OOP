#include "stdafx.h"
#include "screen_work.h"

ACTION_RET Alloc_Memory_Screen(Scr_Arr &arr, M_Points points)
{
	Scr_Pnt *pnt = new Scr_Pnt[points.Np]; 

	if (!pnt)
		return FATAL_ERROR;

	arr.point = pnt;
	arr.Ns = points.Np;

	return SUCCESS_ACT;
}

Scr_Arr Init_Screen()
{
	Scr_Arr arr;

	arr.point = nullptr;
	arr.Ns = 0;

	return arr;
}

void Draw_Line(Graphics^ canvas, Scr_Pnt p1, Scr_Pnt p2, Color col)
{
	Draw_Line_Canvas(canvas, Convert_To_Canvas_Point(p1.X, p1.Y), Convert_To_Canvas_Point(p2.X, p2.Y), col);
}
