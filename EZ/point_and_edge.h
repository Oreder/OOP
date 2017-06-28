#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "errors.h"
#include "file_stream.h"

struct Edges
{
	int e1;
	int e2;
};

struct Coord
{
	double x;
	double y;
	double z;
};

ACTION_RET Read_One_Point(Coord &point, File_Stream in);
ACTION_RET Read_One_Edge(Edges &edge, File_Stream in);