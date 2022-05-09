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

bool square_matrix_check(size_t n, size_t m)
{
    if (n != m)
        return false;
    return true;
}

bool parity_check(int n)
{
    if (n % 2 == 0)
        return true;
    return false;
}

int min_odd_number_under_diagonal(int a[NMAX][NMAX], size_t n)
{
    int min = 0;
    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (!parity_check(a[i][j]))
            {
                if (min == 0)
                    min = a[i][j];
                else
                {
                    if (a[i][j] < min)
                        min = a[i][j];
                }
            }
        }
    }
    return min;
}

int main(void)
{
    int matrix[NMAX][NMAX];
    size_t row, column;
    
    printf("Enter the number of rows and columns of the matrix: ");
    if (scanf("%zu%zu", &row, &column) != 2 ||
        row > N || row < 1 || column < 1 || column > N)
    {
        printf("Error: incorrect data.\n");
        return EXIT_FAILURE;
    }
    if (!square_matrix_check(row, column))
    {
        printf("Error: the matrix must be square!\n");
        return EXIT_FAILURE;
    }
    printf("Enter matrix elements:\n");
    if (!matrix_input(matrix, row, column))
    {
        printf("Error: incorrect data.\n");
        return EXIT_FAILURE;
    }
    
    int min_number = min_odd_number_under_diagonal(matrix, row);
    
    if (min_number == 0)
    {
        printf("There are no odd numbers under the main diagonal.\n");
        return EXIT_FAILURE;
    }
    printf("Minimum odd number: ");
    printf("%d\n", min_number);
    
    return EXIT_SUCCESS;
}
