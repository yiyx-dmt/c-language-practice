#include<stdio.h>

int cal(int a);

int main()
{ 
    int a; int b; long int c;
    scanf("%d %d",&a,&b);
    
    int d,e;
    d = cal(a);
    e = cal(b);
    c = d * 1000 + e;
    printf("a=%d,b=%d,c=%ld\n", a, b, c);
}
int cal(int a)
{
    int x,y,z;
        x = a % 10;
        y = (a % 100 - x) / 10;
        z = a / 100 %10;
        return x*100 + y*10 + z;
}