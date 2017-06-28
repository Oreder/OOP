//		������ � ������� - �������� �� �����, ��������

#include "stdafx.h"
#include "model.h"
#include "loadmodel.h"

//������������ ������ ������
void ClearModel (sModel *mdl)
{
	ClearPointsList (&(mdl->points));
	ClearEdgesList(&(mdl->edges));
	delete mdl;
}

//��������� ������ ��� ������ + �������������
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


//��������� ������ �� �����
eCodeFile LoadModel (sModel *&mdl, char *filename)
{
	FILE *f = fopen(filename, "r");

	if (!f)
		return cfNotFound;

	//���������� ��� �������� �������� ������
	sModel *newmodel = InitializeModel();
	if (!newmodel)
		return cfOutOfMemory;

	eCodeFile res = LoadAll (newmodel, f);
	fclose(f);
	if (res==cfFine)
	{
		//���� �����-�� ������ ��� ����, ������� ��
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

//������ � ������ ������: ��������
eCodeFile FileProcess(sModel *&mdl, char *filename, eFileAction action)
{
	if (action == faLoad)
		return LoadModel(mdl, filename);

	return cfUnkNownAction; 
}
