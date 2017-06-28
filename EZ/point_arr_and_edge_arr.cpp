#include "stdafx.h"
#include "point_arr_and_edge_arr.h"

ACTION_RET Read_Number_Points(M_Points &points, File_Stream in)
{
	if (fscanf(in.f, "%d", &(points.Np)) != 1)
		return WRONG_DATA;
	return SUCCESS_ACT;
}

ACTION_RET Read_Number_Edges(M_Edges &edges, File_Stream in)
{
	if (fscanf(in.f, "%d", &(edges.Ne)) != 1)
		return WRONG_DATA;
	return SUCCESS_ACT;
}

ACTION_RET Read_Points(M_Points &points, File_Stream in)
{
	ACTION_RET res = SUCCESS_ACT;

    for (int i = 0; (i < points.Np) && (res == SUCCESS_ACT); i++)
		res = Read_One_Point(points.pnt[i], in);

	return res;
}

ACTION_RET Read_Edges(M_Edges &edges, File_Stream in)
{
	ACTION_RET res = SUCCESS_ACT;

    for (int i = 0; (i < edges.Ne) && (res == SUCCESS_ACT); i++)
		res = Read_One_Edge(edges.edg[i], in);

	return res;
}

ACTION_RET Alloc_Memory_Points(M_Points &points)
{
	points.pnt = new Coord[points.Np];

	if (!points.pnt)
		return FATAL_ERROR;

	return SUCCESS_ACT;
}

ACTION_RET Alloc_Memory_Edges(M_Edges &edges)
{
	edges.edg = new Edges[edges.Ne];

	if (!edges.edg)
		return FATAL_ERROR;

	return SUCCESS_ACT;
}

void Free_Memory_Points(M_Points &points)
{
	if (!points.pnt)
		return;

	delete points.pnt;
	points.pnt = nullptr;
	points.Np = 0;
}
	
void Free_Memory_Edges(M_Edges &edges)
{
	if (!edges.edg)
		return;

	delete edges.edg;
	edges.edg = nullptr;
	edges.Ne = 0;
}