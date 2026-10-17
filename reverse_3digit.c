#include<stdio.h>
int main()
{
    int i;
    scanf("%d", &i);

    int a = i / 100;
    int c = i % 10;
    int b = i % 100 / 10;
    
    //printf("%d%d%d\n", c, b, a);
    int d = c * 100 + b * 10 + a;
    printf("%d\n", d);
    return 0;
}