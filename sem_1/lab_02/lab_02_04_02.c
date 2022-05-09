#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 10
#define NMAX 1024

size_t in_array(int arr[])
{
    size_t i = 0;
    while (scanf("%d", &arr[i]) == 1)
    {
        i++;
        if (i > N)
            return i;
    }
    return i;
}

void print_array(int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selection_sort(int arr[], size_t len)
{
    for (size_t i = 0; i < len - 1; i++)
    {
        size_t position = i;
        for (size_t j = i + 1; j < len; j++)
            if (arr[position] > arr[j])
                position = j;
        if (position != i)
        {
            double swap = arr[i];
            arr[i] = arr[position];
            arr[position] = swap;
        }
    }
}

int main(void)
{
    int array[NMAX];
    bool flag = true;
    
    printf("Enter array elements: ");
    size_t lenght = in_array(array);
    if (lenght == 0)
    {
        printf("Error: incorrect data.\n");
        return EXIT_FAILURE;
    }
    if (lenght > N)
    {
        flag = false;
        lenght = N;
    }
    selection_sort(array, lenght);
    printf("Result array: ");
    print_array(array, lenght);
    if (!flag)
        return 100;
    return EXIT_SUCCESS;
}
