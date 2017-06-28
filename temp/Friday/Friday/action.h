#pragma once

#include "render.h"

void SetCanvas(sEasel *easel, sEasel *easel1);
//void SetCanvas (sEasel *easel, sCanvasContainer *canv);
void ChangeScale(sRenderData *rend, double scale);
void ChangeRotation(sRenderData *rend, sMove move);
void SetRotation(sRenderData *rend, sMove move);
void ChangeShift(sRenderData *rend, sMove move);


