#pragma once
#include <stdio.h>

struct sEdge //�����
{
	int from, to; //������ � ������� �����, ������� ����� ���������
};

struct sPoint3d
{
	double x,y,z;
};

enum eCodeFile
{
	cfFine,         //������ ���
	cfNotFound,     //���� �� ������
	cfCorrupted,    //���������
	cfOutOfMemory,  //�� ������� ������
	cfUnkNownAction // ����������� ������
};

eCodeFile LoadCountPoints (int &n, FILE *fl);
eCodeFile LoadEdgesCount (int &n, FILE *fl);
eCodeFile LoadPoint(sPoint3d *point, FILE *fl);
eCodeFile LoadEdge (sEdge *edge, FILE *fl);