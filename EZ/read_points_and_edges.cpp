#include "stdafx.h"
#include "read_points_and_edges.h"

ACTION_RET Read_Points_Arr(M_Points &points, File_Stream in)
{
	ACTION_RET res = SUCCESS_ACT;

	res = Read_Number_Points(points, in);
	if (res == WRONG_DATA)
		return res;

	res = Alloc_Memory_Points(points);

	if (res == FATAL_ERROR)
		return res;
 
	res = Read_Points(points, in);

	if (res == WRONG_DATA)
	{
	    Free_Memory_Points(points);
		return res;
	}

	return res;
}

ACTION_RET Read_Edges_Arr(M_Edges &edges, File_Stream in)
{
	ACTION_RET res = SUCCESS_ACT;
	res = Read_Number_Edges(edges, in);

	if (res == WRONG_DATA)
		return res;

	res = Alloc_Memory_Edges(edges);

	if (res == FATAL_ERROR)
		return res;

	res = Read_Edges(edges, in);

	if (res == WRONG_DATA)
	{
		Free_Memory_Edges(edges);
		return res;
	}

	return res;
}
