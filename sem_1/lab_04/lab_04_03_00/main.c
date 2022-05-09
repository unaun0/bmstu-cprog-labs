#include "my_funcs.h"

int main(void)
{
    char array_words[MAX_LEN][MAX_LEN];
    char str[NMAX];
    char result[MAX_LEN];
    
    printf("Enter the string: ");
    if (fgets(str, NMAX, stdin) == NULL || str[strlen(str) - 1] != '\n')
        return EXIT_FAILURE;
    if (strlen(str) > MAX_LEN)
        return EXIT_FAILURE;
    int lenght = split_string(array_words, str);
    if (lenght < 2)
        return EXIT_FAILURE;
    creating_new_string(array_words, result, lenght);
    if (strlen(result) < 1)
        return EXIT_FAILURE;
    printf("Result: %s\n", result);
    
    return EXIT_SUCCESS;
}
