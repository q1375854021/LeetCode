#include <stdio.h>
#include <stdlib.h>

#ifndef _COMMON_H
#define _COMMON_H

#define CHECK_FUNC(call)                                                       \
{                                                                              \
    const int result = call;                                                   \
    if (result != 0)                                                           \
    {                                                                          \
        fprintf(stderr, "Error: %s:%d, ", __FILE__, __LINE__);                 \
        exit(1);                                                               \
    }                                                                          \
}

#endif