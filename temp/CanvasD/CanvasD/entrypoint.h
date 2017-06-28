#pragma once

#include <gcroot.h>

#include "render.h"
#include "conversion.h"
#include "file.h"

//перечислитель команд: инициализировать данные, загрузить из файла, масштабировать, вращать,
//установить угол поворота, перемещать
enum eChangeAction {caInit, caLoad, caScale, caRotate, caSetRot, caShift, caClear};

union uChangeData
{
	sMove move; //смещение
	double scale; //масштаб
	sEasel *canvas;
	char *filename; //им€ файла дл€ открыти€
	bool clear;
	//char mb; //зажата€ кнопка мыши
	//sCanvasContainer *canvas; //обЄртка дл€ холста
	
};


//непосредственно обработчик всех и вс€ческих изменений
eCodeFile Apply (eChangeAction action, uChangeData *data, sEasel *easel=nullptr);