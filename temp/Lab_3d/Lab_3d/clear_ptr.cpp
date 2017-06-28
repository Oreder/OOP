#include "clear_ptr.h"
#include <stdlib.h>
void Clear_Ptr(void * ptr)
{
    free(ptr);
}
