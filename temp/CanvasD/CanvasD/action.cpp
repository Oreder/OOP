//		Изменение параметров отрисовки модели

#include "stdafx.h"
#include "action.h"
#include "render.h"
#include "conversion.h"
#include "matrix.h"


//поворот
void ChangeRotation (sRenderData *rend, sMove move)
{
	rend->rotx += move.dx;
	rend->roty += move.dy;
	rend->rotz += move.dz;
}

void SetCanvas (sEasel *easel, sEasel *easel1)
//void SetCanvas (sEasel *easel, sCanvasContainer *canv)
{
	/*easel->canvas = canv->pb->CreateGraphics();
	easel->cx = canv->pb->Width/2;
	easel->cy = canv->pb->Height/2;
	easel->backColor = canv->pb->BackColor;*/
	easel->canvas = easel1->canvas;
	easel->cx = easel1->cx;
	easel->cy = easel1->cy;
	easel->backColor = easel1->backColor;

}

//изменение масштаба модели
void ChangeScale (sRenderData *rend, double scale)
{
	rend->scale = scale;
}

//установка углов
void SetRotation (sRenderData *rend, sMove move)
{
	rend->rotx = move.dx;
	rend->roty = move.dy;
	rend->rotz = move.dz; 
}

//смещение
void ChangeShift (sRenderData *rend, sMove move)
{
	rend->dx += move.dx;
	rend->dy += move.dy;
	rend->dz += move.dz;

} 