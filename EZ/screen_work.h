#pragma once
#include "point_arr_and_edge_arr.h"
#include "canvas_work.h"

struct Scr_Pnt
{
	int X;
	int Y;
};

struct Scr_Arr
{
	int Ns;
	Scr_Pnt *point;
};

ACTION_RET Alloc_Memory_Screen(Scr_Arr &arr, M_Points points);
Scr_Arr Init_Screen();
void Draw_Line(Graphics^ canvas, Scr_Pnt p1, Scr_Pnt p2, Color col);