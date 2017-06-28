//		������ � ������������ ������

#include "stdafx.h"
#include "loadmodel.h"
#include "file.h"

//����������� ������ ��-��� ��������� ������ ������
void ClearPointsList (sPointsList *p)
{
	if (!p)
		return;
	if (p->pointsArray)
	{
		delete p->pointsArray;
		p->pointsArray = nullptr;
		p->count=0;
	}
}


//����������� ������ ��-��� ��������� ����� ������
void ClearEdgesList (sEdgesList *e)
{
	if (!e)
		return;
	delete e->edgesArray;
	e->edgesArray = nullptr;
	e->count = 0;
}

//��������� ������ ����� � ���������
eCodeFile LoadPoints(sPointsList *points, FILE *f)
{
	eCodeFile res = cfFine;

	for (int i = 0;  (i < points->count) && (res == cfFine);  i++)
	{
		res = LoadPoint(&(points->pointsArray[i]), f);
	}

	return res;
}



//��������� ������ ����� � ���������
eCodeFile LoadEdges (sEdgesList *edges, FILE *f)
{
	eCodeFile res = cfFine;

	for (int i=0; (i<edges->count)&&(res==cfFine); i++)
		res = LoadEdge (&(edges->edgesArray[i]), f); //[i]

	return res;
}


//�������� ������ ��� ��������� ������ ������
eAllocError AllocPointList (sPointsList *points)
{
	points->pointsArray = new sPoint3d[points->count];
	if (!points->pointsArray)
		return aeOutOfMemory;

	return aeFine;
}


//�������� ������ ��� ��������� ����� ������
eAllocError AllocEdgesList (sEdgesList *edges)
{
	edges->edgesArray = new sEdge[edges->count];
	if (!edges->edgesArray)
		return aeOutOfMemory;
		return aeFine;
}

//��������, ����� �� ��������� �������
eCodeFile TryPoints (sPointsList *points, FILE *f)
{
	eCodeFile res = LoadCountPoints(points->count, f);
		if (res != cfFine)
			return res;
	if (AllocPointList(points) == aeOutOfMemory) 
		return cfOutOfMemory;

	res = LoadPoints (points, f);

	if (res!=cfFine)
		ClearPointsList (points);

	return res;
}


//��������, ����� �� ��������� ����
eCodeFile TryEdges (sEdgesList *edges, FILE *f)
{
	eCodeFile res = LoadEdgesCount(edges->count, f);
	if (res!=cfFine)
		return res;

	if (AllocEdgesList(edges) == aeOutOfMemory)
		return cfOutOfMemory;

	res = LoadEdges (edges, f);

	if (res!=cfFine)
		ClearEdgesList(edges);

	return res;
}


