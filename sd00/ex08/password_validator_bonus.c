#include "password_validator.h"

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int pw_strlen(const char *pw)
{
    int i;

    i = 0;
    if (pw == NULL)
        return 0;
    while (pw[i] != '\0')
        i++;
    return i;
}

int edit_distance(const char *new_pw, const char *pw)
{
    int i;
    int j;
    int m;
    int n;

    i = 0;
    j = 0;
    if (new_pw == NULL || pw == NULL)
        return 0;
    m = pw_strlen(new_pw);
    n = pw_strlen(pw);
    int dp[m + 1][n + 1];

    while (i <= m)
    {
        dp[i][0] = i;
        i++;
    }
    while (j <= n)
    {
        dp[0][j] = j;
        j++;
    }
    i = 1;
    while(i <= m)
    {
        j = 1;
        while (j <= n)
        {
            if (new_pw[i - 1] == pw[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            j++;
        }
        i++;
    }
    /* printf("Edit distance between '%s' and '%s' is %d\n", new_pw, pw, dp[m][n]); */
    return dp[m][n];
}


int differs(const char *new_pw, PasswordHistory *history)
{
    char *pw;
    if (new_pw == NULL || history == NULL)
        return 0;
    
    pw = history->pw;
    while (pw != NULL)
    {
        if (edit_distance(new_pw, pw) < 2)
            return 0;
        history = history->next;
        if (history == NULL)
            break;
        pw = history->pw;
    }
    return 1;
}