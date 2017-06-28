//		��������� ���������� ��������� ������

#include "stdafx.h"
#include "action.h"
#include "render.h"
#include "conversion.h"
#include "matrix.h"


//�������
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

//��������� �������� ������
void ChangeScale (sRenderData *rend, double scale)
{
	rend->scale = scale;
}

//��������� �����
void SetRotation (sRenderData *rend, sMove move)
{
	rend->rotx = move.dx;
	rend->roty = move.dy;
	rend->rotz = move.dz; 
}

//��������
void ChangeShift (sRenderData *rend, sMove move)
{
	rend->dx += move.dx;
	rend->dy += move.dy;
	rend->dz += move.dz;

} 