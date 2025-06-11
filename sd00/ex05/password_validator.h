#ifndef PASSWORD_VALIDATOR_H
#define PASSWORD_VALIDATOR_H

typedef enum PWStatus
{
    VALID,
    INVALID
} PwStatus;

PwStatus validate_password(const char *new_pw, const char *curr_pw);

int digit(const char *pw);
int low_char(const char *pw);
int up_char(const char *pw);
int lenght(const char *pw);
int special_char(const char *pw);
int differs(const char *new_pw, const char *curr_pw);

#endif