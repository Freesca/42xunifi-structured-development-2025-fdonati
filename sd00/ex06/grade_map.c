#include "grade_map.h"
/* #include <stdio.h> */


void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
    int i;
    char *grade;

    i = 0;
    grade = NULL;
    if (scores == NULL || mapped_grades == NULL || size <= 0)
        return;

    if (mapper == MAP_A)
    {
        while (i < size)
        {
            if (scores[i] >= 0 && scores[i] <= 59)
                mapped_grades[i] = "F";
            if (scores[i] >= 60 && scores[i] <= 62)
                mapped_grades[i] = "D-";
            if (scores[i] >= 63 && scores[i] <= 66)
                mapped_grades[i] = "D";
            if (scores[i] >= 67 && scores[i] <= 69)
                mapped_grades[i] = "D+";
            if (scores[i] >= 70 && scores[i] <= 72)
                mapped_grades[i] = "C-";
            if (scores[i] >= 73 && scores[i] <= 76)
                mapped_grades[i] = "C";
            if (scores[i] >= 77 && scores[i] <= 79)
                mapped_grades[i] = "C+";
            if (scores[i] >= 80 && scores[i] <= 82)
                mapped_grades[i] = "B-";
            if (scores[i] >= 83 && scores[i] <= 86)
                mapped_grades[i] = "B";
            if (scores[i] >= 87 && scores[i] <= 89)
                mapped_grades[i] = "B+";
            if (scores[i] >= 90 && scores[i] <= 92)
                mapped_grades[i] = "A-";
            if (scores[i] >= 93 && scores[i] <= 96)
                mapped_grades[i] = "A";
            if (scores[i] >= 97 && scores[i] <= 100)
                mapped_grades[i] = "A+";
            i++;
        }
    }
    else if (mapper == MAP_B)
    {
        while (i < size)
        {
            if (scores[i] >= 0 && scores[i] <= 59)
                mapped_grades[i] = "F";
            if (scores[i] >= 60 && scores[i] <= 100)
                mapped_grades[i] = "P";
            i++;
        }
    }
    else if (mapper == MAP_C)
    {
        while (i < size)
        {
            if (scores[i] >= 0 && scores[i] <= 59)
                mapped_grades[i] = "F";
            if (scores[i] >= 60 && scores[i] <= 69)
                mapped_grades[i] = "C";
            if (scores[i] >= 70 && scores[i] <= 79)
                mapped_grades[i] = "B";
            if (scores[i] >= 80 && scores[i] <= 100)
                mapped_grades[i] = "A";
            i++;
        }
    }
    return;
}

int main()
{
    int scores[] = {85, 92, 76, 45, 100, 67};
    const char *mapped_grades[6];
    int size = sizeof(scores) / sizeof(int);
    GradeMapper mapper = MAP_B;

    map_scores(scores, size, mapper, mapped_grades);

/*     for (int i = 0; i < size; i++)
    {
        printf("Score: %d, Grade: %s\n", scores[i], mapped_grades[i]);
    } */

    return 0;
}