#include "stdafx.h"
#include "entry.h"

ACTION_RET Main_Function (Entry_Data *data, Selected_Action action)
{
	ACTION_RET res = SUCCESS_ACT;

	static Figure_Param figure = Init_Model();
	static Canvas_Param cur_canvas;

	switch (action)
	{
		case INIT_ACT:
			res = Init_Canvas(cur_canvas, data->canvas);
			break;

		case LOAD_ACT:
			res = Load_Data(figure, data->filename, FILE_LOAD);
			break;

		case SCALE_ACT:
			res = Scale_Model(figure, data->scale);
			break;

		case ROTATE_ACT:
			res = Rotate_Model(figure, data->rotate);
			break;

		case SHIFT_ACT:
			res = Shift_Model(figure, data->shift);
			break;

		case CLOSE_ACT:
			Free_Model(figure);
			break;

		//default:
			/// ERROR IF NO ACTION
	}

	if (res == SUCCESS_ACT)
		res = Draw_Model(figure, cur_canvas);

	return res;
}