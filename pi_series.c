#include<stdio.h>
int main()
{   int n;
    float pi2;
    pi2 = 0.0;
    int i;
    double x = 1.0;

    scanf("%d",&n);

    for(i = 1;i <= n + 1;i++){
        if(i > 1){
            x *= 1.0*(i - 1)/(2*i-1);
        }
        pi2 += x;
    }


    printf("n=%d,pi2=%f\n", n, pi2);
    return 0;
}