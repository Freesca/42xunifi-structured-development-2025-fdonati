#ifndef PASSWORD_VALIDATOR_H
#define PASSWORD_VALIDATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum PWStatus
{
    VALID,
    INVALID_WEAK,
    INVALID_SIMILAR
} PwStatus;

typedef struct PasswordHistory
{
    char *pw;
    struct PasswordHistory *next;
} PasswordHistory;
    

PwStatus validate_password(const char *new_pw,  PasswordHistory *history);

int digit(const char *pw);
int low_char(const char *pw);
int up_char(const char *pw);
int lenght(const char *pw);
int special_char(const char *pw);
int differs(const char *new_pw, PasswordHistory *history);

#endif