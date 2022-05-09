#include "my_funcs.h"

void delete_spaces(char str[])
{
    int len = strlen(str);
    while (isspace(*str))
    {
        for (int i = 0; i < len; i++)
            str[i] = str[i + 1];
        len--;
    }
    char *s1 = str + len - 1;
    while (isspace(*s1))
        s1--;
    *(s1 + 1) = '\0';
}

bool is_byte(char n[])
{
    if (strlen(n) > MAX_COUNT || strlen(n) < 1)
        return false;
    int num = atoi(n);
    if (num >= BYTE)
        return false;
    return true;
}

bool is_digit(char n)
{
    if (n <= '9' && n >= '0')
        return true;
    return false;
}

bool is_ip_address(char str[])
{
    delete_spaces(str);
    int i = 0, j = 0;
    int len = strlen(str);
    if (len < N || !is_digit(str[len - 1]))
        return false;
    char number[MAX_LEN];
    int point = 0;
    while (i < len)
    {
        if (str[i] != '.' && !(is_digit(str[i])))
            return false;
        if (str[i] == '.')
        {
            number[j] = '\0';
            if (!is_byte(number))
                return false;
            point++;
            j = 0;
            strcpy(number, "");
            i++;
            continue;
        }
        number[j] = str[i];
        j++;
        i++;
    }
    number[j] = '\0';
    if (!is_byte(number))
        return false;
    if (point != MAX_COUNT)
        return false;
    return true;
}
