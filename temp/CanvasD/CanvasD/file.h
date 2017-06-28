#pragma once
#include <stdio.h>

struct sEdge //ребро
{
	int from, to; //номера в массиве точек, которые ребро соединяет
};

struct sPoint3d
{
	double x,y,z;
};

enum eCodeFile
{
	cfFine,         //ошибок нет
	cfNotFound,     //файл не найден
	cfCorrupted,    //поврежден
	cfOutOfMemory,  //не хватает памяти
	cfUnkNownAction // неизвестная ошибка
};

eCodeFile LoadCountPoints (int &n, FILE *fl);
eCodeFile LoadEdgesCount (int &n, FILE *fl);
eCodeFile LoadPoint(sPoint3d *point, FILE *fl);
eCodeFile LoadEdge (sEdge *edge, FILE *fl);