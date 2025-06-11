#include "password_validator.h"

int special_char(const char *pw)
{
    int i;

    i = 0;
    while (pw[i] != '\0')
    {
        if ((pw[i] >= '!' && pw[i] <= '/') || (pw[i] >= ':' && pw[i] <= '@') ||
            (pw[i] >= '[' && pw[i] <= '`') || (pw[i] >= '{' && pw[i] <= '~') ||
            pw[i] == ' ')
            return 1;
        i++;
    }
    return 0;
}

int digit(const char *pw)
{
    int i;

    i = 0;
    while (pw[i] != '\0')
    {
        if (pw[i] >= '0' && pw[i] <= '9')
            return 1;
        i++;
    }
    return 0;
}

int low_char(const char *pw)
{
    int i;

    i = 0;
    while (pw[i] != '\0')
    {
        if (pw[i] >= 'a' && pw[i] <= 'z')
            return 1;
        i++;
    }
    return 0;
}

int up_char(const char *pw)
{
    int i;

    i = 0;
    while (pw[i] != '\0')
    {
        if (pw[i] >= 'A' && pw[i] <= 'Z')
            return 1;
        i++;
    }
    return 0;
}

int lenght(const char *pw)
{
    int i;

    i = 0;
    while (pw[i] != '\0')
        i++;
    return (i >= 8);
}

PwStatus validate_password(const char *new_pw, PasswordHistory *history)
{
    if (new_pw == NULL || history == NULL)
        return INVALID_WEAK;

    if (!(lenght(new_pw) && up_char(new_pw) && low_char(new_pw) &&
        digit(new_pw) && special_char(new_pw)))
        return INVALID_WEAK;
    if (!(differs(new_pw, history)))
        return INVALID_SIMILAR;
    return VALID;
}

/* int main()
{
    // Example usage of the password validator
    PasswordHistory *history;
    history = malloc(sizeof(PasswordHistory));
    history->pw = strdup("OldPassword123!");
    history->next = malloc(sizeof(PasswordHistory));
    history->next->pw = strdup("AnotherPassword456!");
    history->next->next = malloc(sizeof(PasswordHistory));
    history->next->next->pw = strdup("YetAnotherPassword789!");

    PwStatus status;

    status = validate_password("NewPassword123!", history);
    if (status == VALID)
        printf("Password is valid.\n");
    else if (status == INVALID_WEAK)
        printf("Password is weak.\n");
    else if (status == INVALID_SIMILAR)
        printf("Password is similar to previous passwords.\n");
    else
        printf("Password is invalid.\n");

    return 0;
} */