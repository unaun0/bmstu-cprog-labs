#include "stdio.h"
#include "stdlib.h"
#include <stdint.h>
#include <inttypes.h>

void trans(uint32_t number, int const n)
{
    int num;

    printf("Result: ");
    for (int i = 31; i >= 0; i--)
    {
        num = (number >> (i + (n % 32))) % 2;
        printf("%d", num);
    }
    printf("\n");
}

int main()
{
    uint32_t number;
    int n;
    
    printf("Enter a: ");
    if (scanf("%" SCNu32, &number) != 1)
    {
        printf("Error: decimal number is integer.\n");
        return EXIT_FAILURE;
    }
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Error:number of shifts is a positive integer.\n");
        return EXIT_FAILURE;
    }
    trans(number, n);
    return EXIT_SUCCESS;
}
