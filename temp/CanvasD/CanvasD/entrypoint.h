#pragma once

#include <gcroot.h>

#include "render.h"
#include "conversion.h"
#include "file.h"

//������������� ������: ���������������� ������, ��������� �� �����, ��������������, �������,
//���������� ���� ��������, ����������
enum eChangeAction {caInit, caLoad, caScale, caRotate, caSetRot, caShift, caClear};

union uChangeData
{
	sMove move; //��������
	double scale; //�������
	sEasel *canvas;
	char *filename; //��� ����� ��� ��������
	bool clear;
	//char mb; //������� ������ ����
	//sCanvasContainer *canvas; //������ ��� ������
	
};


//��������������� ���������� ���� � ��������� ���������
eCodeFile Apply (eChangeAction action, uChangeData *data, sEasel *easel=nullptr);