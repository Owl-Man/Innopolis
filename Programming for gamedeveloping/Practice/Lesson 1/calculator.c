#include <stdio.h>
#include <stdlib.h> #include <string.h>

int sum(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

int main(int count, char *args[])
{
    char plus_symbol[] = "+";
    char minus_symbol[] = "-";
    char multiply_symbol[] = "*";
    char divide_symbol[] = "/";

    if (count < 4) return 0;

    int a = atoi(args[1]);
    int b = atoi(args[3]);

    if (strcmp(args[2], plus_symbol) == 0) 
        printf("%d", sum(a, b));
    else if (strcmp(args[2], minus_symbol) == 0) 
        printf("%d", subtract(a, b));
    else if (strcmp(args[2], multiply_symbol) == 0) 
        printf("%d", multiply(a, b));
    else if (strcmp(args[2], divide_symbol) == 0) 
        printf("%f", divide(a, b));
    else
        printf("Invalid");
}

int sum(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}


int multiply(int a, int b)
{
    return a * b;
}

double divide(int a, int b)
{
    if (b == 0) return 0;
    return (double)a / b;
}
