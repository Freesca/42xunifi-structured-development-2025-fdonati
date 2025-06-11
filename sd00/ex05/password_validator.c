#include "password_validator.h"

int differs(const char *new_pw, const char *curr_pw)
{
    int i;

    i = 0;

    if (new_pw == NULL || curr_pw == NULL)
        return 0;

    while (new_pw[i] != '\0' && curr_pw[i] != '\0')
    {
        if (new_pw[i] != curr_pw[i])
            return 1;
        i++;
    }
    return (new_pw[i] != curr_pw[i]);
}

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

PwStatus validate_password(const char *new_pw, const char *curr_pw)
{
    if (new_pw == NULL || curr_pw == NULL)
        return INVALID;

    if (lenght(new_pw) && up_char(new_pw) && low_char(new_pw) &&
        digit(new_pw) && special_char(new_pw) && differs(new_pw, curr_pw))
        return VALID;
    return INVALID;
}