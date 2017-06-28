//		Непосредственно отрисовка модели
//#include "stdafx.h"
#include "render.h"
#include "canvas.h"
#include "conversion.h"


//рисование ребра
void DrawEdge (sConvertedPoint *converted, sEasel *easel, sEdge *edge)
{
	int x1=easel->cx;
	int y1=easel->cy;
	sCanvasPoint p1 = CanvasPoint(easel->cx + converted->Xs[edge->from], easel->cy - converted->Ys[edge->from]);
	sCanvasPoint p2 = CanvasPoint(easel->cx + converted->Xs[edge->to], easel->cy - converted->Ys[edge->to]);
	DrawLine1(easel->canvas,
		p1,p2
		);
}


//рисование всех ребер
void DrawEdges (sConvertedPoint *converted, sEasel *easel, sEdgesList *links)
{
	for (int i=0; i<links->count;i++)
		DrawEdge(converted, easel,&(links->edgesArray[i]));
}



void ClearCanvas (sEasel *easel)
{
	easel->canvas->Clear(Color::LightYellow);

}

//рисование всей модели
void DrawModel(sModel *mdl, sEasel *easel, sRenderData *params)
{
	if (!mdl || !easel || !params)
		return;


	sConvertedPoint *conv = Converts (&(mdl->points), params);
	if (!conv)
		return;

	ClearCanvas(easel);

	DrawEdges(conv, easel, &(mdl->edges));
	ClearConvertedPoints(conv);

	return;
}