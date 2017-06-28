#pragma once
#include "read_points_and_edges.h"

struct Figure_Param
{
	M_Points s_points;
	M_Edges s_edges;
};

ACTION_RET Read_Model(Figure_Param &figure, File_Stream in);
void Free_Model(Figure_Param &figure);