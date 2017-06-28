#pragma once

#include "loadmodel.h"

//смещение модели
struct sMove
{
	double dx;
	double dy;
	double dz;
};

//параметры переотрисовки
struct sRenderData
{
	double rotx, roty, rotz; //поворот
	double dx, dy, dz; //перемещение
	double scale; //масштаб
};

//точки в целочисленных координатах
//используются при непосредственно отрисовке
struct sConvertedPoint
{
	int count;
	int *Xs;
	int *Ys;
};


sConvertedPoint *Converts (sPointsList *points, sRenderData *params);
void ClearConvertedPoints (sConvertedPoint *converted);