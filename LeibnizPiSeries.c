#include<stdio.h>
int main()
{ 
    int n;
    float pi;
    int sign = 1;
    int i;
    pi = 0;

    scanf("%d",&n);
    for(i = 1;i <= n;i++){
        pi += sign*(4.0 / (2*i-1));
        sign = -sign;
    }



    printf("n=%d,pi=%.3f\n",n, pi);
}