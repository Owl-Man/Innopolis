#include "my_assert.h"

int main()
{
    int value = 10;

    my_assert(value > 0, "value must be positive");

    printf("program 1 finished\n");

    return 0;
}
