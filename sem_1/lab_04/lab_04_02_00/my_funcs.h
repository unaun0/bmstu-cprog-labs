#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NMAX 1024
#define MAX_LEN 257
#define N 17

int split_string(char arr[MAX_LEN][MAX_LEN], const char *string);
bool deleting_word(char arr[MAX_LEN][MAX_LEN], int n, int index);
int remove_words(char arr[MAX_LEN][MAX_LEN], int n);
void counter(char words[MAX_LEN][MAX_LEN], int a[], int n, int m);
void print_counter(char words[MAX_LEN][MAX_LEN], int a[], int n);
