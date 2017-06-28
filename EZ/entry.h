#pragma once
#include "load_file.h"
#include "transform.h"

enum Selected_Action 
{
	CLOSE_ACT,
	INIT_ACT, 
	LOAD_ACT, 
	SCALE_ACT, 
	ROTATE_ACT, 
	SHIFT_ACT
};

struct Entry_Data
{
	Param_Shift shift;		
	Param_Scale scale;	
	Param_Rotate rotate;
	Canvas_Itself *canvas;	
	char *filename;	
};

ACTION_RET Main_Function (Entry_Data *data, Selected_Action action);