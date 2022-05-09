#include "stdio.h"
#include "stdlib.h"
#include "math.h"
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
            {
                return false;
            }
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

void insert_row_of_100(int a[NMAX][NMAX], size_t index, size_t n, size_t m)
{
    for (size_t i = n - 1; i >= index; i--)
    {
        for (size_t j = 0; j < m; j++)
            a[i + 1][j] = a[i][j];
    }
    for (size_t i = 0; i < m; i++)
        a[index][i] = 100;
}

int last_digit(int n)
{
    while (n > 9)
        n /= 10;
    return n;
}

size_t rows_checking(int a[NMAX][NMAX], int num, size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        int first_digit_count = 0, last_digit_count = 0;
        for (size_t j = 0; j < m; j++)
        {
            if (abs(a[i][j]) % 10 == num)
                last_digit_count++;
            if (last_digit(abs(a[i][j])) == num)
                first_digit_count++;
        }
        if (first_digit_count == last_digit_count && first_digit_count > 0)
        {
            i++;
            insert_row_of_100(a, i, n, m);
            n++;
        }
    }
    return n;
}

int main(void)
{
    int matrix[NMAX][NMAX];
    size_t row, column;
    int number;
    
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
    printf("Enter a number: ");
    if (scanf("%d", &number) != 1 || number >= N || number < 0)
    {
        printf("Error: incorrect number.\n");
        return EXIT_FAILURE;
    }
    row = rows_checking(matrix, number, row, column);
    printf("Matrix:\n");
    print_matrix(matrix, row, column);
    
    return EXIT_SUCCESS;
}
