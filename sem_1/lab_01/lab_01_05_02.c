#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAX_VAL 9223372036854775807.5

int main()
{
    int number;
    unsigned long long int a, b, c;
    int k = 2;
    
    printf("Enter the number: ");
    if (scanf("%d", &number) != 1 || number < 0)
    {
        printf("Error: number positive integer.");
        return EXIT_FAILURE;
    }
    a = 0;
    b = 1;
    if (number == 0)
        c = a;
    if (number == 1)
        c = b;
    while (k <= number)
    {
        if (b > MAX_VAL)
        {
            printf("Error: overflow.\n");
            return EXIT_FAILURE;
        }
        c = a + b;
        a = b;
        b = c;
        k++;
    }
    printf("%llu\n", c);
    return EXIT_SUCCESS;
}
