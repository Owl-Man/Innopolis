#include <stdio.h>

int fibonacci(int n)
{
    if (n > 2) return fibonacci(n - 1) + fibonacci(n - 2);

    return 1;
}

int main()
{
    for (int n = 1; n <= 10; n++) 
        printf("x(%d) = %d\n", n, fibonacci(n));
}
