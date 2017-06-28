#pragma once
#include "read_coordinates.h"
#include "canvas_work.h"
#include "screen_work.h"

ACTION_RET Find_Zoom(M_Points arr, Scr_Arr scr, Canvas_Param cur_canvas);
ACTION_RET Convert_Point(Scr_Pnt &out, Coord in, Canvas_Param canvas, double zoom);
double Find_Max (M_Points arr);
double Compare_Num (Coord point, double num);
double Assign_Num (Coord point);