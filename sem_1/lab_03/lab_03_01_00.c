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
            {
                return false;
            }
        }
    }
    return true;
}

void creating_the_resulting_array(int arr[], int a[NMAX][NMAX], size_t n, size_t m)
{
    for (size_t k = 0; k < m; k++)
    {
        bool flag = true;
        if (n > 1)
        {
            for (size_t i = 1; i < n; i++)
            {
                if (a[i - 1][k] <= a[i][k])
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
                arr[k] = 1;
            else
                arr[k] = 0;
        }
        else
            arr[k] = 0;
    }
}

void print_array(int arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int matrix[NMAX][NMAX];
    int result_array[NMAX];
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
    creating_the_resulting_array(result_array, matrix, row, column);
    printf("Result: ");
    print_array(result_array, column);
    
    return EXIT_SUCCESS;
}
