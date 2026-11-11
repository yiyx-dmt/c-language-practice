#include<stdio.h>

int main()
{
    printf("%ld %ld %ld %ld %ld\n",sizeof(char),sizeof(int),sizeof(double),sizeof(long int),sizeof(float));
    char ac[] = {0,1,2,3,4,5,6,7,8,9};
    char *p = ac;
    printf("p  =%p\n",p);
    printf("p+1=%p\n",p+1);

    int ai[] = {0,1,2,3,4,5,6,7,8,9};
    int *q = ai;
    printf("q  =%p\n",q);
    printf("q+1=%p\n",q+1);

    double ad[] = {0,1,2,3,4,5,6,7,8,9};
    double *r = ad;
    printf("r  =%p\n",r);
    printf("r+1=%p\n",r+1);

    long int ae[] = {0,1,2,3,4,5,6,7,8,9};
    long int *s = ae;
    printf("s  =%p\n",s);
    printf("s+1=%p\n",s+1);

    float ag[] = {0,1,2,3,4,5,6,7,8,9};
    float *t = ag;
    printf("t  =%p\n",t);
    printf("t+1=%p\n",t+1);

    return 0;
}