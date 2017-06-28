//		Точка входа, через которую применяются любые действия из интерфейса


#include "stdafx.h"
#include "render.h"

#include "entrypoint.h"
#include "model.h"
#include "action.h"

//обработка действия интерфейса
eCodeFile Apply (eChangeAction action, uChangeData *data, sEasel *easel)
{
	static sRenderData changes; //изменения производимые в модели
	// sEasel easel; //мольберт
	static sModel *model = InitializeModel();

	if (!model) return cfOutOfMemory;
	eCodeFile res = cfFine;
	switch (action)
	{
	case caInit: //инициализация холста
		{
			//
			break;
		}
	case caLoad: //загрузка модели из файла
		{
			res = FileProcess (model,data->filename,faLoad);
			if (res!=cfFine)
				return res;
			break;
		}
	case caScale: //изменение масштаба модели
		{
			ChangeScale (&changes, data->scale);
			break;
		}
	
	case caRotate:  //изменение углов поворота модели
		{
			ChangeRotation (&changes, data->move);
			break;

		}
	case caSetRot: //установка углов поворота модели
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