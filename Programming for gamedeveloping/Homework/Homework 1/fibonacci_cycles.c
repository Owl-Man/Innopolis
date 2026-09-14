#include <stdio.h>

int fibonacci(int end_n)
{
    int pprev = 0;
    int prev = 1;

    for (int n = 1; n <= end_n; n++) 
    {
        if (n == 1) printf("x(%d) = %d\n", n, prev);
        else 
        {
            int current = prev + pprev;
            pprev = prev;
            prev = current;

            printf("x(%d) = %d\n", n, prev);
        }
    }
}

int main()
{
    fibonacci(10);
}
