//		����� �����, ����� ������� ����������� ����� �������� �� ����������


#include "stdafx.h"
#include "render.h"

#include "entrypoint.h"
#include "model.h"
#include "action.h"

//��������� �������� ����������
eCodeFile Apply (eChangeAction action, uChangeData *data, sEasel *easel)
{
	static sRenderData changes; //��������� ������������ � ������
	// sEasel easel; //��������
	static sModel *model = InitializeModel();

	if (!model) return cfOutOfMemory;
	eCodeFile res = cfFine;
	switch (action)
	{
	case caInit: //������������� ������
		{
			//
			break;
		}
	case caLoad: //�������� ������ �� �����
		{
			res = FileProcess (model,data->filename,faLoad);
			if (res!=cfFine)
				return res;
			break;
		}
	case caScale: //��������� �������� ������
		{
			ChangeScale (&changes, data->scale);
			break;
		}
	
	case caRotate:  //��������� ����� �������� ������
		{
			ChangeRotation (&changes, data->move);
			break;

		}
	case caSetRot: //��������� ����� �������� ������
		{
			SetRotation(&changes, data->move);
			break;
		}
	case caShift:
		{
			ChangeShift (&changes, data->move);
			break;
		}
	case caClear:
		{
			ClearModel(model);
			return cfFine;
		}
	default:
		return cfUnkNownAction;
	}
	DrawModel (model, easel, &changes);
	return res;
}