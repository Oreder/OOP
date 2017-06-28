//��������� ���������� ��������� ������

#include "stdafx.h"

#include "actions.h"
#include "render.h"	
#include "conversion.h"
#include "matrix.h"

////������������� ������ 
void SetCanvas (sEasel *easel, sCanvasContainer *canv)
{
	easel->canvas = canv->pb->CreateGraphics();
	easel->cx = canv->pb->Width/2;
	easel->cy = canv->pb->Height/2;
	easel->backColor = canv->pb->BackColor;

}


//��������� �������� ������
void ChangeScale (sRenderData *renderdata, double scale)
{
	renderdata->scale = scale;
}

//������� ������
void ChanngeRotation (sRenderData *renderdata, sMove move)
{
	renderdata->rotx += move.dx;
	renderdata->roty += move.dy;
	renderdata->rotz += move.dz;
}


//��������� ����� ������
void SetRotation (sRenderData *renderdata, sMove move)
{
	renderdata->rotx = move.dx;
	renderdata->roty = move.dy;
	renderdata->rotz = move.dz;
}

//�������� ������
void ChangeShift (sRenderData *renderdata, sMove move)
{
	renderdata->dx += move.dx;
	renderdata->dy += move.dy;
	renderdata->dz += move.dz;
}