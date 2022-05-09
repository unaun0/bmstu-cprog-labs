#include "my_string.h"

int testing_module(void)
{
    char test[TEST][MAX_LEN] =
    {
        "Anna is my mother!",
        "my name is yana.",
        "i don't know",
        "123456789130",
        "12345",
        "000001",
        "12 years",
        "i will be 19 this year",
        "i don't know",
        "123456789130",
        "12345",
        "221213a",
        "years 12",
        "i will be 19 this year",
        "",
        "aqpfg23456  789130das",
        "123545",
        "221213a",
        "Hello, my dear friend!",
        "what's your name? my name is yana",
        "it's 2022 now",
        "Hippopotomonstrosesquipedaliophobia",
        "1",
        "\0"
    };
    char search[TEST][MAX_LEN] =
    {
        "am", "ktqw", "iknow", "0345", "9678", "10",
        "1234567890", "1234567890", "don't know", "123789", "54321", "12345678a90",
        "0asdasd", "p9lijuyq1", "pljuyq", "bsd0123", "540", "45678bsra90",
        "abc", "0", "\0", ",.:;!?", "zxc", "aaaaaa"
    };
    char search_char[TEST] =
    {
        '!', '?', ',', '\0', '0', 'o',
        'a', '1', 's', 'p', 'b', '2',
        'l', 'i', 'Y', 'k', '9', '3',
        'h', 'd', 't', '.', 'q', 'z'
    };
    int count = 0;
    for (int i = 0; i < TEST; i++)
    {
        if (strpbrk(test[i], search[i]) != my_strpbrk(test[i], search[i]))
            count++;
        if (strspn(test[i], search[i]) != my_strspn(test[i], search[i]))
            count++;
        if (strcspn(test[i], search[i]) != my_strcspn(test[i], search[i]))
            count++;
        for (int j = 0; j < TEST; j++)
        {
            if (strchr(test[i], search_char[j]) != my_strchr(test[i], search_char[j]))
                count++;
            if (strrchr(test[i], search_char[j]) != my_strrchr(test[i], search_char[j]))
                count++;
        }
    }
    return count;
}

int main(void)
{
    if (testing_module() > 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

