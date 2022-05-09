#include "my_funcs.h"

int main(void)
{
    char str[NMAX];
    if (fgets(str, NMAX, stdin) == NULL || str[strlen(str) - 1] != '\n')
        return EXIT_FAILURE;
    if (strlen(str) > MAX_LEN || strlen(str) < 1)
        return EXIT_FAILURE;
    
    if (!is_ip_address(str))
        printf("NO\n");
    else
        printf("YES\n");

    return EXIT_SUCCESS;
}
