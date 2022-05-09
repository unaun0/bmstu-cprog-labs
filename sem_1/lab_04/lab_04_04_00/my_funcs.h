#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define NMAX 1024
#define MAX_LEN 257
#define N 7
#define MAX_COUNT 3
#define BYTE 256

void delete_spaces(char str[]);
bool is_byte(char n[]);
bool is_digit(char n);
bool is_ip_address(char str[]);
