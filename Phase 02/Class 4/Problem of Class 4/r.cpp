#include<stdio.h>

int main()
{
    long long  a, b; scanf("%ld%ld",&a,&b);
    char c; scanf("%c%c",&c,&c);
    if (c == '+') printf("%ld\n", a + b);
    else if (c == '-') printf("%ld\n", a - b);
    else if (c == '*') printf("%ld\n", a * b);
    else if (c == '%') printf("%ld\n", a % b);
    else {
      if (b < 1) printf("Division by zero error");
      else printf("%ld\n", a / b);
    }
    return 0;
}