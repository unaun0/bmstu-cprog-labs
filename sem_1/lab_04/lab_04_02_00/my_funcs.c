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

bool deleting_word(char arr[MAX_LEN][MAX_LEN], int n, int index)
{
    bool flag = true;
    if (strcmp(arr[index], arr[index + 1]) == 0)
        flag = false;
    for (int i = index; i < n; i++)
    {
        char temp[N] = "";
        strcpy(temp, arr[i]);
        strcpy(arr[i], arr[i + 1]);
        strcpy(arr[i + 1], temp);
    }
    return flag;
}

int remove_words(char arr[MAX_LEN][MAX_LEN], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        while (j < n)
        {
            if (strcmp(arr[i], arr[j]) == 0)
            {
                n--;
                if (!deleting_word(arr, n, j))
                    continue;
            }
            j++;
        }
    }
    return n;
}

void counter(char words[MAX_LEN][MAX_LEN], int a[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = n; j < m; j++)
            if (strcmp(words[i], words[j]) == 0)
                count++;
        a[i] = count;
    }
}

void print_counter(char words[MAX_LEN][MAX_LEN], int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%s %d\n", words[i], a[i]);
}
