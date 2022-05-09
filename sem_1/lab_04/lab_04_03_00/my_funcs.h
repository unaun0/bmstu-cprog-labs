#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NMAX 1024
#define MAX_LEN 257
#define N 17

int split_string(char arr[MAX_LEN][MAX_LEN], const char *string);
void word_change(char word[], char sc);
void creating_new_string(char arr[MAX_LEN][MAX_LEN], char str[], int n);
