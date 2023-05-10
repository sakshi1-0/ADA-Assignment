18. Implement a divide-and-conquer algorithm for multiplying two large integers.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void add(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len_res = MAX(len_a, len_b) + 1;
    char* res = calloc(len_res, sizeof(char));
    int carry = 0;
    for (int i = 0; i < len_res; i++) {
        int digit_a = i < len_a ? a[len_a - 1 - i] - '0' : 0;
        int digit_b = i < len_b ? b[len_b - 1 - i] - '0' : 0;
        int sum = digit_a + digit_b + carry;
        res[len_res - 1 - i] = sum % 10 + '0';
        carry = sum / 10;
    }
    int i = 0;
    while (i < len_res - 1 && res[i] == '0') {
        i++;
    }
    memmove(a, res + i, len_res - i + 1);
    free(res);
}

char* karatsuba(char* x, char* y) {
    int len_x = strlen(x);
    int len_y = strlen(y);
    if (len_x == 1 || len_y == 1) {
        int xy = atoi(x) * atoi(y);
        char* res = calloc(16, sizeof(char));
        sprintf(res, "%d", xy);
        return res;
    }
    int n = MAX(len_x, len_y);
    if (n % 2 != 0) {
        n++;
    }
    char* x_pad = calloc(n, sizeof(char));
    char* y_pad = calloc(n, sizeof(char));
    memset(x_pad, '0', n - len_x);
    memset(y_pad, '0', n - len_y);
    memmove(x_pad + n - len_x, x, len_x);
    memmove(y_pad + n - len_y, y, len_y);
    int m = n / 2;
    char* x_l = calloc(m + 1, sizeof(char));
    char* x_r = calloc(m + 1, sizeof(char));
    char* y_l = calloc(m + 1, sizeof(char));
    char* y_r = calloc(m + 1, sizeof(char));
    memmove(x_l, x_pad, m);
    memmove(x_r, x_pad + m, m);
    memmove(y_l, y_pad, m);
    memmove(y_r, y_pad + m, m);
    char* p1 = karatsuba(x_l, y_l);
    char* p2 = karatsuba(x_r, y_r);
    add(x_l, x_r);
    add(y_l, y_r);
    char* p3 = karatsuba(x_l, y_l);
    char* p4 = calloc(16, sizeof(char));
    memmove(p4, p3, strlen(p3));
    add(p4, p2);
    add(p4, p1);
    int shift = 2 * m;
    char* res = calloc(2 * n + 1, sizeof(char));
    memmove(res + shift, p2, strlen(p2));
    memmove(res + shift * 2, p1, strlen(p1));
    add(res + shift,