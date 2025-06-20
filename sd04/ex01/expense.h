#ifndef EXPENSE_H
#define EXPENSE_H

typedef struct s_expense {
    char date[11];
    float amount;
    char *category;
    char *description;
    struct s_expense *next;
} t_expense;

typedef struct s_summary {
    int total_records;
    float total_amount;
    float average;
    struct s_category_stats {
        char *name;
        float total;
        float percentage;
    } *categories;
    int category_count;
} t_summary;

#endif