#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#include <stdio.h>
#include <stdlib.h>

#ifdef MY_DEBUG

#define my_assert(expr, message) \
    do { \
        if (!(expr)) { \
            fprintf(stderr, \
                    "%s:%d: %s: my_assert: %s: %s\n", \
                    __FILE__, \
                    __LINE__, \
                    __func__, \
                    #expr, \
                    message); \
            abort(); \
        } \
    } while (0)

#else

#define my_assert(expr, message) do { } while (0)

#endif

#endif
