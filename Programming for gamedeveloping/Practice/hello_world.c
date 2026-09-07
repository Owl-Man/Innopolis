#include <stdio.h>

int main()
{
    int some[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double someDouble[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char text[8] = "qwertyui";
    char *a = text;

    printf("Hello, world!\n");

    printf("text = %s \n", a);

    for (int i; i < sizeof(some) / sizeof(some[0]); i++)
        printf("%d \n", some[i]);

    for (int d; d < sizeof(some) / sizeof(some[0]); d++) 
        printf("%f \n", someDouble[d]);

    return 0;
}
