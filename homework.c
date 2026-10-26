#include<stdio.h>

int main()
{
    int x;
    scanf("%d",&x);

    if(x == 0)      printf("1\n");
    else if(x == 1) printf("11\n");
    else if(x == 2) printf("22\n");
    else if(x == 3) printf("222\n");
    else            printf("-1\n");

    return 0;
}