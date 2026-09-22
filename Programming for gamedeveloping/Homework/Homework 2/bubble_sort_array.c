#include <stdio.h>
#include <stddef.h>

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

            if (compare(a, b) > 0) {
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

int compare_int(const void *a, const void *b)
{
    int current = *(const int *)a;
    int next = *(const int *)b;

    if (current > next) 
        return 1;

    if (current < next) 
        return -1;

    return 0;
}

void print_int_array(const char *title, const int *arr, size_t n)
{
    printf("%s\n", title);

    for (size_t i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n\n");
}

int main()
{
    int numbers[10] = {42, 7, 13, 99, 1, 55, 23, 8, 64, 31};

    print_int_array("Before sort:", numbers, 10);

    bubble_sort(numbers, 10, sizeof(numbers[0]), compare_int);

    print_int_array("After sort:", numbers, 10);

    return 0;
}
