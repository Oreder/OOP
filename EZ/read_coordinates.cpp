#include "stdafx.h"
#include "read_coordinates.h"

void Free_Model(Figure_Param &figure)
{
	Free_Memory_Edges(figure.s_edges);
	Free_Memory_Points(figure.s_points);
}

ACTION_RET Read_Model(Figure_Param &figure, File_Stream in)
{
	if (&in == nullptr)
		return NO_DATA;

	ACTION_RET res = SUCCESS_ACT;

	res = Read_Points_Arr(figure.s_points, in);

	if (res != SUCCESS_ACT)
		return res;
	
	res = Read_Edges_Arr(figure.s_edges, in);

	if (res != SUCCESS_ACT)
	{
		Free_Memory_Points(figure.s_points);
		return res;
	}

	return res;
}