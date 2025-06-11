#include "first_last.h"
/* #include <stdio.h> */

void first_last(int arr[], int size, int target, int *first, int *last)
{
    int i;

    i = 0;
    if (first == NULL || last == NULL)
        return;
    if (size <= 0 || arr == NULL)
    {
        *first = -1;
        *last = -1;
        return;
    }
    while (i < size && arr[i] != target)
        i++;
    if (i == size)
        *first = -1;
    else
        *first = i;

    i = size - 1;
    while (i >= 0 && arr[i] != target)
        i--;
    if (i < 0)
        *last = -1;
    else
        *last = i;
}

/* int main()
{
    int arr[] = {1, 2, 3, 4, 5, 3, 6};
    int first;
    int *last;
    last = NULL;
    first_last(arr, 7, 1, &first, last);
    perror("last is NULL, so it will not be printed");
    printf("First occurrence: %d\n", first);
    printf("Last occurrence: %p\n", last);
    return 0;
} */