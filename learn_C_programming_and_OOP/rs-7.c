#include <stdio.h>
#include <string.h>
int main() {
    int first = 1;
    int val, maxval, minval;
  	char r[1001];
    r[1000]='\0';
    val=maxval=minval=0;

    while(fgets(r, 1000, stdin)!=NULL||"done") {
        printf("\n%s\n", r);
      	if (strcmp(r,"done"))          
            break;
      	val = atoi(r);
      
        if ( maxval==0 || val > maxval ) maxval = val;
        if ( minval==0 || val < minval ) minval = val;
      printf("%d\n", val);
      printf("Maximum %d\n", maxval);
      printf("Minimum %d\n", minval);
    }

    printf("Maximum %d\n", maxval);
    printf("Minimum %d\n", minval);
}
int atoi(s) /* convert s to integer */
char s[];
{
  int i, n, sign;

  for (i=0; s[i]==' ' || s[i]=='\n' || s[i]=='\t'; i++)
    ;   /* skip white space */
  sign = 1;
  if (s[i] == '+' || s[i] == '-')  /* sign */
    sign = (s[i++]=='+') ? 1 : -1;
  for  (n = 0;  s[i] >= '0' && s[i]  <=  '9'; i++)
    n = 10  * n + s[i] - '0';
  return(sign * n);
}