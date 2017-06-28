//�������� ������ �� �����

//#include "stdafx.h"

#include <stdio.h>
#include "file.h"

//���������� �� ����� ����� �����
eCodeFile LoadCountPoints (int &n, FILE *fl)
{
	int count;

	if (fscanf(fl, "%d", &count) != 1)
		return cfCorrupted;

	n = count;
	return cfFine;
}

//���������� �� ����� ����� ����
eCodeFile LoadEdgesCount (int &n, FILE *fl)
{
	int count;

	if (fscanf (fl, "%d", &count) != 1)
		return cfCorrupted;
	n = count;
	return cfFine;
}

//���������� �� ����� ����� �����
eCodeFile LoadPoint(sPoint3d *point, FILE *fl)
{
	if (fscanf(fl, "%lf %lf %lf", &point->x, &point->y, &point->z) != 3)
		return cfCorrupted;

	return cfFine;
}


//���������� �� ����� ������ �����
eCodeFile LoadEdge (sEdge *edge, FILE *fl)
{
	if (fscanf(fl, "%d %d", &edge->from, &edge->to) != 2)
		return cfCorrupted;

	return cfFine;
}