#include "my_funcs.h"

int split_string(char arr[MAX_LEN][MAX_LEN], const char *string)
{
    bool flag = true;
    int i = 0, j = 0;

    for (const char *p = string; *p != '\0'; p++)
    {
        if (*p == ' ' || *p == ',' || *p == ';' || *p == ':'
            || *p == '-' || *p == '.' || *p == '!' || *p == '?')
        {
            arr[i][j] = '\0';
            if (strlen(arr[i]) > N)
                return -1;
            if (!flag)
                i++;
            flag = true;
            j = 0;
            continue;
        }
        if (*p != '\n')
        {
            arr[i][j] = *p;
            flag = false;
            j++;
        }
    }
    if (!flag)
    {
        arr[i][j] = '\0';
        if (strlen(arr[i]) > N)
            return -1;
        i++;
    }
    return i;
}

void word_change(char word[], char sc)
{
    if (strlen(word) < 2)
        return;
    int i, j;
    for (i = j = 1; word[i] != '\0'; i++)
        if (word[i] != sc)
            word[j++] = word[i];
    word[j] = '\0';
}

void creating_new_string(char arr[MAX_LEN][MAX_LEN], char str[], int n)
{
    str[0] = '\0';
    char last_word[N] = "";
    strcpy(last_word, arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (strcmp(arr[i], last_word) == 0)
            continue;
        char first_character = arr[i][0];
        word_change(arr[i], first_character);
        strcat(str, arr[i]);
        if (i != 0)
            strcat(str, " ");
    }
}

