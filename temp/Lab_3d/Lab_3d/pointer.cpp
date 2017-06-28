#include "pointer.h"

void* Get_mem(size_t size_type, size_t count)
{
    return malloc(count * size_type);
}

void Clear_Ptr(void * ptr)
{
	free(ptr);
}