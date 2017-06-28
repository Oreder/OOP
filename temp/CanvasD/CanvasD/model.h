#pragma once

#include <stdio.h>
#include "loadmodel.h"
#include "file.h"

//��������� ������
struct sModel
{
	sPointsList points; //������� ������
	sEdgesList edges; //����� ������
};

//������������� �������� ��� ������ ������: ��������
enum eFileAction {faLoad, faSave};

sModel *InitializeModel();
eCodeFile FileProcess(sModel *&mdl, char *filename, eFileAction action);
void ClearModel (sModel *mdl);

eCodeFile LoadAll (sModel *&newmodel, FILE *f);