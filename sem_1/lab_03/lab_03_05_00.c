#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define NMAX 64

#define N 10

bool matrix_input(int a[NMAX][NMAX], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (scanf("%d", &a[i][j]) != 1)
                return false;
        }
    }
    return true;
}

void print_matrix(int a[NMAX][NMAX], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

bool is_prime_number(int n)
{
    if (n <= 1)
        return false;
    int div = 2;
    while (div * div <= n)
    {
        if (n % div == 0)
            return false;
        div++;
    }
    return true;
}

size_t array_of_primes(int a[NMAX][NMAX], int arr[], size_t n, size_t m)
{
    size_t lenght = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (is_prime_number(a[i][j]))
            {
                arr[lenght] = a[i][j];
                lenght++;
            }
        }
    }
    return lenght;
}

void permutation_of_matrix_primes(int a[NMAX][NMAX], int arr[], size_t len, size_t n, size_t m)
{
    len--;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (is_prime_number(a[i][j]))
            {
                a[i][j] = arr[len];
                len--;
            }
        }
    }
}

int main(void)
{
    int matrix[NMAX][NMAX];
    int array[NMAX * NMAX];
    size_t row, column;
    
    printf("Enter the number of rows and columns of the matrix: ");
    if (scanf("%zu%zu", &row, &column) != 2 ||
        row > N || row < 1 || column < 1 || column > N)
    {
        printf("Error: incorrect data.\n");
        return EXIT_FAILURE;
    }
    printf("Enter matrix elements:\n");
    if (!matrix_input(matrix, row, column))
    {
        printf("Error: incorrect data.\n");
        return EXIT_FAILURE;
    }
    size_t lenght = array_of_primes(matrix, array, row, column);
    if (lenght < 1)
    {
        printf("There are no prime numbers in the matrix.\n");
        return EXIT_FAILURE;
    }
    permutation_of_matrix_primes(matrix, array, lenght, row, column);
    printf("Matrix:\n");
    print_matrix(matrix, row, column);
    
    return EXIT_SUCCESS;
}
