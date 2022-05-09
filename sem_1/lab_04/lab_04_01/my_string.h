#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define TEST 24
#define MAX_LEN 257

char *my_strpbrk(const char *str, const char *str_char_set);
size_t my_strspn(const char *str, const char *search_str);
size_t my_strcspn(const char *str, const char *search_str);
char *my_strchr(const char *string, int symbol);
char *my_strrchr(const char *string, int symbol);
