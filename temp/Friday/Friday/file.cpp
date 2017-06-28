//загрузка данных из файла

//#include "stdafx.h"

#include <stdio.h>
#include "file.h"

//считывание из файла числа точек
eCodeFile LoadCountPoints (int &n, FILE *fl)
{
	int count;

	if (fscanf(fl, "%d", &count) != 1)
		return cfCorrupted;

	n = count;
	return cfFine;
}

//считывание из файла числа рёбер
eCodeFile LoadEdgesCount (int &n, FILE *fl)
{
	int count;

	if (fscanf (fl, "%d", &count) != 1)
		return cfCorrupted;
	n = count;
	return cfFine;
}

//считывание из файла ОДНОЙ точки
eCodeFile LoadPoint(sPoint3d *point, FILE *fl)
{
	if (fscanf(fl, "%lf %lf %lf", &point->x, &point->y, &point->z) != 3)
		return cfCorrupted;

	return cfFine;
}


//считывание из файла ОДНОГО ребра
eCodeFile LoadEdge (sEdge *edge, FILE *fl)
{
	if (fscanf(fl, "%d %d", &edge->from, &edge->to) != 2)
		return cfCorrupted;

	return cfFine;
}