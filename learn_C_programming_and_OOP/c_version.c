#include <stdio.h>

int main() {
    #ifdef __STDC_VERSION__
        if (__STDC_VERSION__ >= 201710L) {
            printf("The C version is C18 or later.\n");
        } else if (__STDC_VERSION__ >= 201112L) {
            printf("The C version is C11.\n");
        } else if (__STDC_VERSION__ >= 199901L) {
            printf("The C version is C99.\n");
        } else {
            printf("The C version is C89/C90 with Amendment 1 (C95).\n");
        }
    #else
        printf("The C version is C89/C90 (pre-C99).\n");
    #endif
    return 0;
}