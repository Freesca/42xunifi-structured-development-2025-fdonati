#ifndef CRITICAL_WINDOWS_H
#define CRITICAL_WINDOWS_H

int count_critical_windows(const int *readings, int size);
int is_window_critical(const int *readings, int i, int window_end);
int first_condition(const int *readings, int i, int window_end);
int second_condition(const int *readings, int i, int window_end);
int third_condition(const int *readings, int i, int window_end);

#endif