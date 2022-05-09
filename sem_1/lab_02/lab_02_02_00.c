#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 10
#define NMAX 1024

void print_array(int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf(" %d", arr[i]);
    printf("\n");
}

int calc_average(int arr[], size_t n)
{
    int sum = 0;
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        count ++;
    }
    int average = sum / count;
    return average;
}

size_t build_new_array(int arr[], int res[], size_t len, int av)
{
    size_t count = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (arr[i] > av)
        {
            res[count] = arr[i];
            count++;
        }
    }
    return count;
}

bool in_array(int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1)
            return false;
    return true;
}

int main(void)
{
    int array[NMAX];
    int result[NMAX];
    size_t lenght;

    printf("Enter the number of elements in the array: ");
    if (scanf("%zu", &lenght) != 1 || lenght > N || lenght == 0)
    {
        printf("Error: incorrect data.\n");
        return EXIT_FAILURE;
    }
    printf("Enter array elements: ");
    if (!in_array(array, lenght))
    {
        printf("Error: incorrect data.\n");
        return EXIT_FAILURE;
    }
    int average = calc_average(array, lenght);
    size_t count = build_new_array(array, result, lenght, average);
    if (count < 1)
    {
        printf("Array is empty.\n");
        return EXIT_FAILURE;
    }
    printf("Result array: ");
    print_array(result, count);
    
    return EXIT_SUCCESS;
}
