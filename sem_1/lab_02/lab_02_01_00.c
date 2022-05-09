#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 10
#define NMAX 1024

int even_number(int n)
{
    if (n % 2 == 0)
        return 0;
    else
        return 1;
}

bool in_array(int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1)
            return false;
    return true;
}

int sum_evens(int arr[], size_t n)
{
    int sum = 0;
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (even_number(arr[i]) == 0)
        {
            sum += arr[i];
            count++;
        }
    }
    if (count < 1)
        return EXIT_FAILURE;
    return sum;
}

int main(void)
{
    int array[NMAX];
    size_t num;
    
    printf("Enter the number of elements in the array: ");
    if (scanf("%zu", &num) != 1 || num > N || num == 0)
    {
        printf("Error: incorrect value.\n");
        return EXIT_FAILURE;
    }
    printf("Enter array elements: ");
    if (!in_array(array, num))
    {
        printf("Error: incorrect data.\n");
        return EXIT_FAILURE;
    }
    int result = sum_evens(array, num);
    if (result == EXIT_FAILURE)
    {
        printf("No even numbers in the array.\n");
        return EXIT_FAILURE;
    }
    printf("Sum of even numbers: %d\n", result);
    return EXIT_SUCCESS;
}

