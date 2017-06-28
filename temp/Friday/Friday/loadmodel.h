#pragma once

#include "file.h"

struct sEdgesList
{
	int count;
	sEdge *edgesArray;
};

struct sPointsList
{
	int count;
	sPoint3d *pointsArray;
};

enum eAllocError {aeFine, aeOutOfMemory};

void ClearPointsList (sPointsList *p);
void ClearEdgesList (sEdgesList *e);

eCodeFile TryPoints (sPointsList *points, FILE *f);
eCodeFile TryEdges (sEdgesList *edges, FILE *f);

