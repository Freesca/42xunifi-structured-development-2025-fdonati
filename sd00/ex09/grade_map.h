#ifndef GRADE_MAP_H
#define GRADE_MAP_H

#include <stdlib.h>

typedef enum GradeMapper
{
    MAP_A,
    MAP_B,
    MAP_C
} GradeMapper;

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

GradeNode *compute_distribution(const char **mapped_grades, int size);
void print_distribution(GradeNode *head);
void free_distribution(GradeNode *head);

#endif