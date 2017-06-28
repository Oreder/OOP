//		–абота с моделью - загрузка из файла, удаление

#include "stdafx.h"
#include "model.h"
#include "loadmodel.h"

//освобождение пам€ти модели
void ClearModel (sModel *mdl)
{
	ClearPointsList (&(mdl->points));
	ClearEdgesList(&(mdl->edges));
	delete mdl;
}

//выделение пам€ти под можель + инициализаци€
sModel *InitializeModel()
{
	sModel *mdl = new sModel;
	if (!mdl)
		return nullptr;

	mdl->edges.count = 0;
	mdl->edges.edgesArray = nullptr;
	mdl->points.count = 0;
	mdl->points.pointsArray = nullptr;

	return mdl;
}


//загрузить модель из файла
eCodeFile LoadModel (sModel *&mdl, char *filename)
{
	FILE *f = fopen(filename, "r");

	if (!f)
		return cfNotFound;

	//используем дл€ загрузки буферную модель
	sModel *newmodel = InitializeModel();
	if (!newmodel)
		return cfOutOfMemory;

	eCodeFile res = LoadAll (newmodel, f);
	fclose(f);
	if (res==cfFine)
	{
		//если кака€-то модель уже была, удал€ем ее
		if (mdl)
		{
			ClearModel(mdl);
			//delete mdl;
		}
		mdl = newmodel;

		return cfFine;
	}
	else
	{
		ClearModel(newmodel);
		return res;
	}
}

eCodeFile LoadAll (sModel *&newmodel, FILE *f)
{
	eCodeFile res = TryPoints (&(newmodel->points), f);
	if (res != cfFine)
		return res;

	res = TryEdges(&(newmodel->edges), f);
	if (res != cfFine)
		ClearPointsList(&(newmodel->points));
	return res;
}

//работа с файлом модели: загрузка
eCodeFile FileProcess(sModel *&mdl, char *filename, eFileAction action)
{
	if (action == faLoad)
		return LoadModel(mdl, filename);

	return cfUnkNownAction; 
}
