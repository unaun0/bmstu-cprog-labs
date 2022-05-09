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

void matrix_row_swap(int a[NMAX][NMAX], size_t i, size_t j, size_t m)
{
    for (size_t elm = 0; elm < m; elm++)
    {
        int temp_element = a[i][elm];
        a[i][elm] = a[j][elm];
        a[j][elm] = temp_element;
    }
}

int sum_of_row_elements(int a[NMAX][NMAX], size_t n, size_t m)
{
    int sum = 0;
    for (size_t i = 0; i < m; i++)
        sum += a[n][i];
    return sum;
}

void sorting_matrix_rows(int a[NMAX][NMAX], size_t n, size_t m)
{
    for (size_t i = 0 ; i < n - 1; i++)
    {
        for (size_t j = 0 ; j < n - i - 1 ; j++)
        {
            if (sum_of_row_elements(a, j, m) > sum_of_row_elements(a, j + 1, m))
                matrix_row_swap(a, j, j + 1, m);
        }
    }
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

    printf("Enter matrix elements:\n");
    if (!matrix_input(matrix, row, column))
    {
        printf("Error: incorrect data.\n");
        return EXIT_FAILURE;
    }
    
    sorting_matrix_rows(matrix, row, column);
    printf("Matrix:\n");
    print_matrix(matrix, row, column);

    return EXIT_SUCCESS;
}
