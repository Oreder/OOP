#include "stdafx.h"
#include "point_and_edge.h"

ACTION_RET Read_One_Point(Coord &point, File_Stream in)
{
	if (fscanf(in.f, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3) 
			return WRONG_DATA;

	return SUCCESS_ACT;
}

ACTION_RET Read_One_Edge(Edges &edge, File_Stream in)
{
	if (fscanf(in.f, "%d %d", &edge.e1, &edge.e2) != 2) 
			return WRONG_DATA;

	return SUCCESS_ACT;
}