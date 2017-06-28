#pragma once

#include <stdio.h>
#include "loadmodel.h"
#include "file.h"

//структура модели
struct sModel
{
	sPointsList points; //вершины модели
	sEdgesList edges; //ребра модели
};

//перечислитель действий над файлом модели: загрузка
enum eFileAction {faLoad, faSave};

sModel *InitializeModel();
eCodeFile FileProcess(sModel *&mdl, char *filename, eFileAction action);
void ClearModel (sModel *mdl);

eCodeFile LoadAll (sModel *&newmodel, FILE *f);