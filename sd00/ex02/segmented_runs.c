#include "segmented_runs.h"
/* #include <stdio.h> */

int count_segments(const int *arr, int size)
{
    int i;
    int y;
    int count;
    int increasing;

    i = 0;
    y = 0;
    count = 0;
    increasing = 0;
    if (size <= 0 || arr == NULL)
        return 0;
    while (i < size)
    {
        while (i < size && arr[i]!= -1)
        {
            if (i >= 1 && arr[i] == arr[i - 1] + 1)
                y++;
            if (y > 1)
                increasing = 1;
            i++;
        }
        if (increasing)
            count++;
        y = 0;
        increasing = 0;
        i++;
    }
    return count;
}

/* int main()
{
    int arr[] = {-1, 3, 4, -1};
    int size = sizeof(arr) / sizeof(int);
    int segments;
    segments = count_segments(arr, size);
    printf("Number of segments: %d\n", segments);
    return 0;
} */