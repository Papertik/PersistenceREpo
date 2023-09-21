//BASE CONVERTER

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include "convert.h"

using namespace std;

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

int to_deci(char *str, int base) {
    int len = strlen(str);
    int power = 1; 
    int num = 0;  
    int i;

    for (i = len - 1; i >= 0; i--)
    {
        if (val(str[i]) >= base)
        {
            printf("Invalid Number");
            return -1;
        }

        num += val(str[i]) * power;
        power = power * base;
    }

    return num;
}

char to_char(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

void str_rev(char* str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}


char* from_deci(char temp[], unsigned long long int input, int base) {
    int i = 0;  // Initialize index of result

    while (input > 0)
    {
        temp[i++] = to_char(input % base);
        input /= base;
    }
    temp[i] = '\0';

    str_rev(temp);

    return temp;
}

int mult_pers_ser(int num) {
    return 0;
}