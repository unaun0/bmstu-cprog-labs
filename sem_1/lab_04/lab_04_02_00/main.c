#include "my_funcs.h"

int main(void)
{
    char array_words[MAX_LEN][MAX_LEN];
    char str[NMAX];
    int count[MAX_LEN];
    if (fgets(str, NMAX, stdin) == NULL || str[strlen(str) - 1] != '\n')
        return EXIT_FAILURE;
    if (strlen(str) > MAX_LEN)
        return EXIT_FAILURE;
    int lenght = split_string(array_words, str);
    if (lenght < 1)
        return EXIT_FAILURE;
    int new_lenght = remove_words(array_words, lenght);
    counter(array_words, count, new_lenght, lenght);
    
    printf("Result: \n");
    print_counter(array_words, count, new_lenght);
    
    return EXIT_SUCCESS;
}

