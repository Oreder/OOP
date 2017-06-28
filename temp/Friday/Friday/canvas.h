#pragma once

using namespace System;
using namespace System::Drawing;

//точка
struct sCanvasPoint
{
	int x;
	int y;
};

sCanvasPoint CanvasPoint (int x, int y);
void DrawLine1 (Graphics^ canvas, sCanvasPoint &from, sCanvasPoint &to, Color drColor=Color::Black);