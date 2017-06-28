#ifndef PRINT_PICTURE
#define PRINT_PICTURE
#include "geometry.h"
using namespace System;
using namespace System::Drawing;

typedef struct 
{ 
	int width;
    int height;
} DRAW_ACTION;

int get_width(DRAW_ACTION act);
void set_width(DRAW_ACTION* act, int value);

int get_height(DRAW_ACTION act);
void set_height(DRAW_ACTION* act, int value);


errs_num Print_3D_to_2D(model_t *mod,DRAW_ACTION act);
void lineto(DRAW_ACTION act, dot_t S, dot_t F);
void Clear_scene(DRAW_ACTION act);

#endif // PRINT_PICTURE

