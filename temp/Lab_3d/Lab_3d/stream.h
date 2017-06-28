#ifndef __STREAM_H__
#define __STREAM_H__
#include <stdio.h>
#define stream_t FILE*

typedef struct stream_type { stream_t F; } stream;

stream_t open_stream(stream *S, char *name);
void Close_stream(stream *S);
int stream_EOF(stream S);
stream_t OpenFile(char *name);
void stream_rewind(stream *S);
stream_t get_stream(stream S);

#endif // __STREAM_H__