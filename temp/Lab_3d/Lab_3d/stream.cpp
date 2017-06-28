#include "stream.h"

stream_t OpenFile(char *name)
{
    return fopen(name,"r");
}

void Close_stream(stream *S)
{
    fclose(S->F);
}

stream_t open_stream(stream *S, char* name)
{
    return S->F = OpenFile(name);
}


int stream_EOF(stream S)
{
    return feof(S.F);
}

char scan_char(stream *S)
{
    char ch;
    if(fscanf(S->F, "%c", &ch))
        return ch;
    return 0;
}

void stream_rewind(stream *S)
{
    rewind(S->F);
}

FILE *get_stream(stream S)
{
    return S.F;
}
