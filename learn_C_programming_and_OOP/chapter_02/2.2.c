#include <stdio.h>
/*
K&R Exercise 2-2.

You should write a function (no #include statements are needed) called htoi(str) that converts hexadecimal constant (base-16 0-9 and a-f) to an integer. There will not be a '0x' prefix (like in C) - just assume the input is a hex number. You should not use ctype.h and your code can assume the ASCII character set.

Each time you run the program, the values you need to convert e37ba (base-16) to 931770 (base-10) may be different each time you run the code.

*/

int main(void){ // DO NOT EDIT
    int htoi();
    printf("htoi('e37ba') = %d\n", htoi("e37ba")); // Expect htoi('e37ba') = 931770
    printf("htoi('f') = %d\n", htoi("f")); // Expect htoi('f') = 15
    printf("htoi('F0') = %d\n", htoi("F0")); // Expect htoi('F0') = 240
    printf("htoi('12fab') = %d\n", htoi("12fab")); // Expect htoi('12fab') = 77739
    return 0;
}
// Begin editable area
int atoi(s) /* convert s to integer */
char s[];
{
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + s[i] - '0';
    return(n);
}
int htoi(char s[]){
/*
Receives a character array, s, and returns an int n.
s is a series of hexadecimal characters, n is the decimal value.
Hypothesis: It is possible to convert the hex value to decimal in a single pass.
However, The goal will be to simply get through this assignment. I will transfer 
this to my github code space.
*/
	printf("%s\n", s);
	return 0;
}
