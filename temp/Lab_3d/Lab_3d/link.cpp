#include "link.h"
#include "ptr.h"

void set_vec_S(vec_t *vec,unsigned int value)
{
    vec->S = value;
}

void set_vec_F(vec_t *vec, unsigned int value)
{
    vec->F = value;
}

unsigned int get_vec_S(vec_t link)
{
    return link.S;
}

unsigned int get_vec_F(vec_t link)
{
    return link.F;
}

void set_arr_vec(link_t *links, vec_t* ptr)
{
    links->link = ptr;
}

void set_vec(link_t *links, int i, vec_t value)
{
    links->link[i] = value;
}

void set_links_count(link_t *links, unsigned int value)
{
    links->count = value;
}

void *get_arr_vec(link_t links)
{
    return (void*) links.link;
}

vec_t get_vec(link_t link, int i)
{
    return link.link[i];
}

unsigned int get_links_count(link_t link)
{
    return link.count;
}

int clear_arr_vec(link_t *links)
{
    Clear_Ptr((void*)links->link);
    return 0;
}
