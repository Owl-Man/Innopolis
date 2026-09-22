#include "my_assert.h"

int main()
{
    int index = 7, size = 5;

    my_assert(index < size, "index must fit array");

    printf("program 3 finished\n");

    return 0;
}
