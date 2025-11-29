#include <stdio.h>

int main(void){
    int n = 5;
    float num;
    float sum;
    float avg;

    for (int i=0; i<n; i++){
        scanf("%f", &num);
        sum+=num;
    }
    printf("\nThe total is: %.1f\nThe average is: %.1f\n", sum, sum/n);
    
    return 0;
}
/*
Input received:
10.0
5.0
15.0
20.0
10.0
Expected output from your program:
The total is: 60.0
The average is: 12.0*/