#include "print_picture.h"
#include "stdio.h"
#include "error.h"
#include "line.h"
#include "dot.h"


errs_num Print_3D_to_2D(model_t *mod, DRAW_ACTION act)
{
    dots_t dots = *get_dots(mod);
    
	if(get_dots_count(dots) == 0)
        return ERR_ZERO;
    
	link_t links = *get_links(mod);
    
	if(get_links_count(links) == 0)
        return ERR_ZERO;
    
	Clear_scene(act);

    for (int i = 0; i < get_links_count(links); i++)
    {
        dot_t S = get_dot(dots,get_vec_S(get_vec(links, i)));
        dot_t F = get_dot(dots,get_vec_F(get_vec(links, i)));
        lineto(act, S, F);
    }

    return NO_ERR;
}

void Clear_scene(DRAW_ACTION act)
{
    get_scene(act)->clear();
}


int get_width(DRAW_ACTION act)
{
    return act.width;
}

int get_height(DRAW_ACTION act)
{
    return act.height;
}

void set_width(DRAW_ACTION *act, int value)
{
    act->width = value;
}

void set_height(DRAW_ACTION *act, int value)
{
    act->height = value;
}