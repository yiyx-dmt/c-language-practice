#include<stdio.h>

int main()
{
    int a;
    int b;
    scanf("%d",&a);
    b = a / 100 * 100 + a % 10;
    printf("a=%d,b=%d\n", a, b);
}