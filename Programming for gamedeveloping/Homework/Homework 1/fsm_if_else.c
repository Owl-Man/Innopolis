#include <stdio.h>

void simulate_fsm(const char *str) 
{
    int state = 0;

    for (int i = 0; str[i] != '\0'; i++) 
    {
        char symbol = str[i];
        int start_state = state;

        if (state == 0) 
        {
            if (symbol == 'a') state = 1;
            else if (symbol == 'b') state = 2;
            else if (symbol == 'c') state = 3;
        } 
        else if (state == 1) 
        {
            if (symbol == 'a') state = 2;
            else if (symbol == 'b') state = 3;
            else if (symbol == 'd') state = 0;
        } 
        else if (state == 2) 
        {
            if (symbol == 'b') state = 3;
            else if (symbol == 'c') state = 1;
            else if (symbol == 'd') state = 0;
        } 
        else if (state == 3) 
        {
            if (symbol == 'c') state = 1;
            else if (symbol == 'a') state = 2;
            else if (symbol == 'd') state = 0;
        }

        printf("Input symbol: %c, Start state: %d, End state: %d\n", symbol, start_state, state);
    }

    printf("\n\n");
}

int main() 
{
    char str1[] = "abcdabcdabcdabcdabcd";
    char str2[] = "aaaabbbbccccddddaaaa";
    char str3[] = "ddddccccbbbbaaaadddd";

    simulate_fsm(str1);
    simulate_fsm(str2);
    simulate_fsm(str3);

    return 0;
}
