#ifndef LOAD_FILE
#define LOAD_FILE
#include <stdio.h>
#include "geometry.h"
#include "stream.h"
#include "error.h"

errs_num Read_Model(model_t *mod, char *name);
errs_num Read_model_from_stream(model_t *mod, stream S);

int _get_count(unsigned int *count, stream S);
errs_num Get_count(unsigned int *count, stream S);

int _get_dot(double *x, double *y, double *z, stream S);
errs_num Get_dot(dot_t *dot, stream S);

int _get_vec(unsigned int *st, unsigned int *fin, stream S);
errs_num Get_vec(vec_t *vec, stream S);

errs_num Read_Model_dots(dots_t *dots,stream S);
errs_num Read_Model_links(link_t *link,stream S);

errs_num _get_dots(dots_t *dots, stream S, unsigned int count);
errs_num _get_links(link_t *link, stream S, unsigned int count);

#endif // LOAD_FILE

