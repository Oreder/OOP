#pragma once
#include "point_and_edge.h"

struct M_Edges
{
	int Ne;         // number of edges
	Edges *edg;     // couple edges
};

struct M_Points
{
	int Np;         // number of points
	Coord *pnt;     // x, y, z point coordinates
};

ACTION_RET Alloc_Memory_Points(M_Points &points);
ACTION_RET Alloc_Memory_Edges(M_Edges &edges);
void Free_Memory_Edges(M_Edges &edges);
void Free_Memory_Points(M_Points &points);
ACTION_RET Read_Number_Points(M_Points &points, File_Stream in);
ACTION_RET Read_Number_Edges(M_Edges &edges, File_Stream in);
ACTION_RET Read_Points(M_Points &points, File_Stream in);
ACTION_RET Read_Edges(M_Edges &edges, File_Stream in);