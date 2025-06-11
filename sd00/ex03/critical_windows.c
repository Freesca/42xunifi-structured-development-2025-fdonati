#include "critical_windows.h"
/* #include <stdio.h> */

int third_condition(const int *readings, int i, int window_end)
{
    int sum;
    
    sum = 0;
    while (i < window_end)
    sum += readings[i++];
return ((sum / 5) >= 90);
}

int second_condition(const int *readings, int i, int window_end)
{
    while (i < window_end)
    {
        if (readings[i++] > 150)
            return 0;
    }
    return 1;
}

int first_condition(const int *readings, int i, int window_end)
{
    int count;

    count = 0;
    while (i < window_end)
    {
        if (readings[i++] >= 70)
            count++;
    }
    return (count >= 3);
}

int is_window_critical(const int *readings, int i, int window_end)
{
    return (first_condition(readings, i, window_end) &&
        second_condition(readings, i, window_end) &&
        third_condition(readings, i, window_end));
}

int count_critical_windows(const int *readings, int size)
{
    int i;
    int count;
    int window_size;

    i = 0;
    count = 0;
    window_size = 5;
    if (size <= 0 || readings == NULL)
        return 0;
    while (1)
    {
        if (i + window_size > size)
            break;
        if (is_window_critical(readings, i, i + window_size))
            count++;
        i++;
    }
    return count;
}

/* int main()
{
    int readings[] = {50, 50, 50, 50, 50};
    int size = sizeof(readings) / sizeof(int);
    int critical_windows;

    critical_windows = count_critical_windows(readings, size);
    printf("Number of critical windows: %d\n", critical_windows);
    return 0;
} */