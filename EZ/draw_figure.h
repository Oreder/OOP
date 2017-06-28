#pragma once
#include "convertation.h"

struct Param_Shift
{
	double dx;
	double dy;
	double dz;
};

struct Param_Rotate
{
	double ox;
	double oy;
	double oz;
};

struct Param_Scale
{
	double kx;
	double ky;
	double kz;
};

ACTION_RET Draw_Model(Figure_Param figure, Canvas_Param cur_canvas);
ACTION_RET Draw_Edges (Scr_Pnt *points, M_Edges edges, Canvas_Param cur_canvas);
ACTION_RET Draw_One_Edge (Scr_Pnt *points, Edges edge, Canvas_Param cur_canvas);