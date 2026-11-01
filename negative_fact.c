#include<stdio.h>

int main()
{  
    int n;
    float f;
    scanf("%d",&n);
    int m = -n;
    float fact = 1.0;
    for(int i = 1;i <= m+1;i++){
        fact *= i;
    }
    f = 1.0 / fact;
    printf("(%d)!=%f\n",n,f);
    return 0;
}