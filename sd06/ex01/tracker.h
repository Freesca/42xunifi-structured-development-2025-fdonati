#ifndef TRACKER_H
#define TRACKER_H

#include "expense.h"

t_expense *load_expenses(const char *filename);
void free_expenses(t_expense *list);

int is_valid_date(const char *date);
int is_valid_amount(float amount);
void normalize_string(char **str);

t_expense *filter_by_category(t_expense *list, const char *substr);
t_expense *filter_by_date_range(t_expense *list, const char *start, const char *end);

t_summary *generate_summary(t_expense *list);
void free_summary(t_summary *summary);

void display_menu();
void display_summary(t_summary *summary);

#endif