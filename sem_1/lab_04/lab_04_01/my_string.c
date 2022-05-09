#include "my_string.h"

char *my_strpbrk(const char *str, const char *str_char_set)
{
    const char *pb;
    int string_character, search_character;
    while ((string_character = *str++) != 0)
    {
        for (pb = str_char_set; (search_character = *pb++) != 0;)
            if (string_character == search_character)
                return ((char *)(str - 1));
    }
    return (NULL);
}

size_t my_strspn(const char *str, const char *search_str)
{
    const char *pb;
    char string_character, search_character;
    size_t len = 0;
    
    while ((string_character = *str++) != 0)
    {
        int flag = 0;
        for (pb = search_str; (search_character = *pb++) != 0;)
            if (string_character == search_character)
            {
                len++;
                flag = 1;
                break;
            }
        if (flag == 0)
            break;
    }
    return len;
}

size_t my_strcspn(const char *str, const char *search_str)
{
    const char *pb;
    char string_character, search_character;
    size_t count = 0;
    while ((string_character = *str++) != 0)
    {
        for (pb = search_str; (search_character = *pb++) != 0;)
            if (string_character == search_character)
                return count;
        count++;
    }
    return count;
}

char *my_strchr(const char *string, int symbol)
{
    const char search_character = symbol;
    
    while (*string != search_character)
    {
        if (*string == '\0')
            return 0;
        string++;
    }
    return (char *) string;
}

char *my_strrchr(const char *str, int symbol)
{
    char *last = 0;
    do 
    {
        if (*str == symbol)
            last = (char *)str;
    }
    while (*str++);
    return last;
}

