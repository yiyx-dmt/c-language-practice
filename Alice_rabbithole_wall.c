#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    int a = 0;
    int b = 0;
    int c;

    for(int i = 0;i < n;i = i + 1)
    {
        scanf("%d",&c);

        if(c == 2 )
        {
            a = a + 1;
        }
        else
        {
            b = b + 1;
        }
    }
    a = a + b / 2;

    printf("%d\n",a);
    return 0;
}