#pragma once
#include "read_coordinates.h"

enum Load_Action
{
	FILE_LOAD
};

Figure_Param Init_Model();
File_Stream Init_Stream();
void Close_Stream(File_Stream fn);
ACTION_RET Open_File(File_Stream &fn, char *filename);
ACTION_RET File_Work(Figure_Param &figure, char* filename);
ACTION_RET Load_Data(Figure_Param &figure, char* filename, Load_Action action);