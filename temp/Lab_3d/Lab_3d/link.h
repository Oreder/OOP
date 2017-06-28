#ifndef LINK
#define LINK

typedef struct VEC_TYPE{
    unsigned int S;
    unsigned int F;
}vec_t;

void set_vec_S(vec_t *vec,unsigned int value);
void set_vec_F(vec_t *vec,unsigned int value);

unsigned int get_vec_S(vec_t link);
unsigned int get_vec_F(vec_t link);
//////////////////////////////////////////////
typedef struct LINK_TYPE{
    vec_t *link;
    unsigned int count;
}link_t;

void set_arr_vec(link_t *links, vec_t *ptr);
void set_vec(link_t *links, int i, vec_t value);
void set_links_count(link_t *links, unsigned int value);

void *get_arr_vec(link_t links);
vec_t get_vec(link_t link, int i);
unsigned int get_links_count(link_t link);

int clear_arr_vec(link_t *links);

//////////////////////////////////////////////

#endif // LINK

