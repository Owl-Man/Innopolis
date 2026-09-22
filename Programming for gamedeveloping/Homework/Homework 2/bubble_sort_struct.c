#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

typedef struct 
{
    char name[16];
    uint64_t score;
    int level;
} Player;

void bubble_sort(void *base, size_t number, size_t width, int (*compare)(const void *, const void *))
{
    if (base == NULL || number < 2 || width == 0 || compare == NULL) 
        return;

    char *arr = (char *)base;
    int swapped;

    do 
    {
        swapped = 0;

        for (size_t i = 0; i < number - 1; ++i) 
        {
            char *a = arr + i * width;
            char *b = arr + (i + 1) * width;

            if (compare(a, b) > 0) 
            {
                for (size_t k = 0; k < width; ++k) 
                {
                    char tmp = a[k];
                    a[k] = b[k];
                    b[k] = tmp;
                }

                swapped = 1;
            }
        }
    } while (swapped);
}

int compare_player(const void *a, const void *b)
{
    const Player *pa = (const Player *)a;
    const Player *pb = (const Player *)b;

    if (pa->score > pb->score) 
        return 1;

    if (pa->score < pb->score) 
        return -1;

    return 0;
}

void print_players(const char *title, const Player *arr, size_t n)
{
    printf("%s\n", title);

    for (size_t i = 0; i < n; ++i) 
    {
        printf("%-10s %10llu %5d\n",
               arr[i].name,
               (unsigned long long)arr[i].score,
               arr[i].level);
    }

    printf("\n");
}

int main(void)
{
    Player players[10] = 
    {
        {"Alice",   500, 3},
        {"Bob",     120, 1},
        {"Charlie", 999, 5},
        {"Dave",     50, 2},
        {"Eve",     750, 4},
        {"Frank",   300, 2},
        {"Grace",   880, 5},
        {"Hank",     10, 1},
        {"Ivy",     440, 3},
        {"Jack",    670, 4}
    };

    print_players("Before sort:", players, 10);

    bubble_sort(players, 10, sizeof(players[0]), compare_player);

    print_players("After sort:", players, 10);

    return 0;
}
