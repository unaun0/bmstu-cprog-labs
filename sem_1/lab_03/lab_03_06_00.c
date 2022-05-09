#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define NMAX 64

#define N 10

void print_matrix(int a[NMAX][NMAX], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void matrix_filling_bull_run(int a[NMAX][NMAX], size_t n, size_t m)
{
    int elem = 1;
    for (size_t i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            for (size_t j = 0; j < n; j++)
            {
                a[j][i] = elem;
                elem++;
            }
        }
        else
        {
            for (size_t j = n; j > 0; j--)
            {
                a[j - 1][i] = elem;
                elem++;
            }
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
    matrix_filling_bull_run(matrix, row, column);
    printf("Matrix:\n");
    print_matrix(matrix, row, column);

    return EXIT_SUCCESS;
}
