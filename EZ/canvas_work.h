#pragma once

#include "errors.h"
#include <gcroot.h>
using namespace System::Drawing;

struct Canvas_Itself
{
	gcroot <System::Windows::Forms::PictureBox^> picture_box;
};

struct Canvas_Param
{
	gcroot<Graphics^> canvas;	
	gcroot<Color> back_color;	
	int cx, cy;					
};

struct Canvas_Point
{
	int X;
	int Y;
};

ACTION_RET Init_Canvas(Canvas_Param &cur_canvas, Canvas_Itself *canvas);
void Draw_Line_Canvas(Graphics^ canvas, Canvas_Point p1, Canvas_Point p2, Color col);
void Clear_Canvas(Canvas_Param cur_canvas);
Canvas_Point Convert_To_Canvas_Point(int x, int y);