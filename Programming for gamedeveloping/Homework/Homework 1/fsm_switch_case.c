#include <stdio.h>

void simulate_fsm(const char *str) 
{
    int state = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char symbol = str[i];
        int start_state = state;

        switch (state) 
        {
            case 0:
                switch (symbol) 
                {
                    case 'a': state = 1; break;
                    case 'b': state = 2; break;
                    case 'c': state = 3; break;
                }
                break;
            case 1:
                switch (symbol) 
                {
                    case 'a': state = 2; break;
                    case 'b': state = 3; break;
                    case 'd': state = 0; break;
                }
                break;
            case 2:
                switch (symbol) 
                {
                    case 'b': state = 3; break;
                    case 'c': state = 1; break;
                    case 'd': state = 0; break;
                }
                break;
            case 3:
                switch (symbol) 
                {
                    case 'c': state = 1; break;
                    case 'a': state = 2; break;
                    case 'd': state = 0; break;
                }
                break;
        }

        printf("Input symbol: %c, Start state: %d, End_state: %d\n", symbol, start_state, state);
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
