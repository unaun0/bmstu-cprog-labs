#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 10
#define NMAX 1024

bool in_array(int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%d", &arr[i]) != 1)
            return false;
    return true;
}

int is_palindrome(int num)
{
    int temp = num;
    int inverted_num = 0;
    while (temp != 0)
    {
        inverted_num = inverted_num * 10 + temp % 10;
        temp /= 10;
    }
    if (num == inverted_num)
        return 0;
    else
        return 1;
}

void rotate(int arr[], size_t n, size_t elm)
{
    for (size_t i = elm; i < n - 1; i++)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void print_array(int arr[], size_t n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

size_t removing_palindromes(int arr[], size_t len)
{
    size_t index = 0;
    while (index < len)
    {
        if (arr[index] >= 0 && is_palindrome(arr[index]) == 0)
        {
            rotate(arr, len, index);
            len--;
        }
        else
            index++;
    }
    return len;
}

int main(void)
{
    int array[NMAX];
    size_t lenght;
    
    printf("Enter the number of elements in the array: ");
    if (scanf("%zu", &lenght) != 1 || lenght > N)
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
    lenght = removing_palindromes(array, lenght);
    if (lenght == 0)
    {
        printf("Array is empty.\n");
        return EXIT_FAILURE;
    }
    printf("Result array: ");
    print_array(array, lenght);
    return EXIT_SUCCESS;
}
