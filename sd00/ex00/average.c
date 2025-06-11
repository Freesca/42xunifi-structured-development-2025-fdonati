#include "average.h"

float average(const int *array, int size)
{
    int i;
    float sum;
    int offset;
    
    i = 0;
    sum = 0.0;
    offset = 0;
    if (size <= 0 || array == NULL)
        return 0.0;
    while (i < size)
    {
        if (array[i] <= 100.0 && array[i] >= 0.0)
        {
            sum += array[i];
        }
        else
            offset++;
        i++;
    }
    return (sum / (size - offset));
}