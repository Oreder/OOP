#pragma once

#include "loadmodel.h"

//�������� ������
struct sMove
{
	double dx;
	double dy;
	double dz;
};

//��������� �������������
struct sRenderData
{
	double rotx, roty, rotz; //�������
	double dx, dy, dz; //�����������
	double scale; //�������
};

//����� � ������������� �����������
//������������ ��� ��������������� ���������
struct sConvertedPoint
{
	int count;
	int *Xs;
	int *Ys;
};


sConvertedPoint *Converts (sPointsList *points, sRenderData *params);
void ClearConvertedPoints (sConvertedPoint *converted);