#include "stdafx.h"
#include "canvas_work.h"

ACTION_RET Init_Canvas(Canvas_Param &cur_canvas, Canvas_Itself *canvas)
{
	if (!canvas)
		return NO_DATA;

	cur_canvas.canvas = canvas->picture_box->CreateGraphics();
	cur_canvas.back_color = canvas->picture_box->BackColor;
	cur_canvas.cx = canvas->picture_box->Width / 2;
	cur_canvas.cy = canvas->picture_box->Height / 2;

	return SUCCESS_ACT;
}

void Draw_Line_Canvas(Graphics^ canvas, Canvas_Point p1, Canvas_Point p2, Color col)
{	
	Pen^ mpen = gcnew Pen(col);
	canvas->DrawLine(mpen, p1.X, p1.Y, p2.X, p2.Y);
	delete mpen;
}

void Clear_Canvas(Canvas_Param cur_canvas)
{
	cur_canvas.canvas->Clear(cur_canvas.back_color);
}

Canvas_Point Convert_To_Canvas_Point(int x, int y)
{
	Canvas_Point point;
	point.X = x;
	point.Y = y;

	return point;
}