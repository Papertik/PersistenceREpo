#ifndef CONVERT
#define CONVERT
#include "convert.cpp"

int val(char c);
int to_deci(char *str, int base);
char to_char(int num);
void str_rev(char* str);
char* from_deci(char temp[], unsigned long long int input, int base);
int mult_pers_ser(int num);

#endif