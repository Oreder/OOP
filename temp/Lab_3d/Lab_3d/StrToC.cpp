#include "StrToC.h"
#include "pointer.h"

char* StringToCharArr(const char* str)
{
    char* buff = (char*) malloc(sizeof(char) * strlen(str));
    strcpy(buff, str);
    return buff;
}

int clear_char_arr(char* str)
{
    Clear_Ptr((void*) str);
    return 0;
}
