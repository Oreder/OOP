#pragma once
#include "stdafx.h"
#include "draw_figure.h"

ACTION_RET Draw_Model(Figure_Param figure, Canvas_Param cur_canvas)
{
	if (&figure == nullptr)
		return NO_DATA;

	ACTION_RET res = SUCCESS_ACT;

	Scr_Arr arr = Init_Screen();

	res = Alloc_Memory_Screen(arr, figure.s_points);

	if (res != SUCCESS_ACT)
		return res;
	
	res = Find_Zoom(figure.s_points, arr, cur_canvas);
	if (res != SUCCESS_ACT)
		return res;

	Clear_Canvas(cur_canvas);
	Draw_Edges(arr.point, figure.s_edges, cur_canvas);

	return res;
}

ACTION_RET Draw_One_Edge (Scr_Pnt *points, Edges edge, Canvas_Param cur_canvas)
{
	if (&edge == nullptr)
		return NO_DATA;

	Draw_Line(cur_canvas.canvas, points[edge.e1], points[edge.e2], Color::Black);

	return SUCCESS_ACT;
}

ACTION_RET Draw_Edges (Scr_Pnt *points, M_Edges edges, Canvas_Param cur_canvas)
{
	if (points == nullptr)
		return NO_DATA;

	if (&edges == nullptr)
		return NO_DATA;

	ACTION_RET res = SUCCESS_ACT;

	for (int i = 0; i < edges.Ne && res == SUCCESS_ACT; i++)
	{
		res = Draw_One_Edge(points, edges.edg[i], cur_canvas);
	}

	return res;
}