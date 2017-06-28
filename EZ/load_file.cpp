#include "stdafx.h"
#include <stdio.h>
#include "load_file.h"
#include "figure.h"

Figure_Param Init_Model()
{
	Figure_Param fig;
	
	Init_figure_Edges(fig.s_edges);

	Init_figure_Points(fig.s_points);

	return fig;
}

ACTION_RET Open_File(File_Stream &fn, char *filename)
{
	FILE *in = fopen(filename, "r");
	if (!in)
		return FILE_NOT_OPEN;

	char c = fgetc(in);

	if (feof(in))
	{
		fclose(in);
		return EMPTY_FILE;
	}

	ungetc(c, in);
	fn.f = in;

	return SUCCESS_ACT;
}

File_Stream Init_Stream()
{
	File_Stream fn;
	fn.f = nullptr;

	return fn;
}

void Close_Stream(File_Stream fn)
{
	fclose(fn.f);
}

ACTION_RET File_Work(Figure_Param &figure, char* filename)
{
	File_Stream fn = Init_Stream();

	ACTION_RET res = Open_File(fn, filename);	

	if (res != SUCCESS_ACT)
		return res;

	Figure_Param new_fig = Init_Model();

	res = Read_Model(new_fig, fn);
	Close_Stream(fn);

	if (res == SUCCESS_ACT)
	{
		Free_Model(figure);
		figure = new_fig;
	}

	return res;
}

ACTION_RET Load_Data(Figure_Param &figure, char* filename, Load_Action action)
{
	ACTION_RET res = SUCCESS_ACT;

	switch (action)
	{
		case FILE_LOAD: // load figure data from file
			res = File_Work(figure, filename);
		break;
	}

	return res;
}