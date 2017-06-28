//Рисуем на холсте

//#include "stdafx.h"

#include "canvas.h"

sCanvasPoint CanvasPoint (int x, int y)
{
	sCanvasPoint pt;
	pt.x = x;
	pt.y = y;

	return pt;
}

void DrawLine1 (Graphics^ canvas, sCanvasPoint &from, sCanvasPoint &to, Color drColor)
{
	Pen^ drPen = gcnew Pen(drColor,1);
	canvas->DrawLine(drPen, from.x, from.y, to.x, to.y);
	delete drPen;
}
