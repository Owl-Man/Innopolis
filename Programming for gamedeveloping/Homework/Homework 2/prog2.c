#include "my_assert.h"

int main()
{
    int value = -5;

    my_assert(value >= 0, "value must be non-negative");

    printf("program 2 finished\n");

    return 0;
}
