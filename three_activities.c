#include <stdio.h>
int main()
{
    int n;
    int a[100];
    int b[100];
    int c[100];
    
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&c[i]);
    }
    int max = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(i != j && i != k && j != k)
                {
                    int sum = a[i]+b[j]+c[k];
                    if(sum > max)
                    {
                        max = sum;
                    }
                }
            }
        }
    }
    printf("%d",max);
    return 0;
}