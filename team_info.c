#include<stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);

    char str1[35];
    char str2[15];
    int c,d,e,f;
    for(int cnt = 1;cnt <= n;cnt++)
    {
        scanf("%s %s %d-%d-%d %d",str1,str2,&c,&d,&e,&f);
        if(f == 1 && d < 10 && e < 10)
        {
            printf("gdut_%s %s %d-0%d-0%d\n",str1,str2,c,d,e,f);
        }else if(f == 1 && d >= 10 && e < 10)
        {
            printf("gdut_%s %s %d-%d-0%d\n",str1,str2,c,d,e,f);
        }else if(f == 1 && d < 10 && e >= 10)
        {
            printf("gdut_%s %s %d-0%d-%d\n",str1,str2,c,d,e,f);
        }else if(f == 1 && d >= 10 && e >= 10)
        {
            printf("gdut_%s %s %d-0%d-0%d\n",str1,str2,c,d,e,f);
        }
    }
    return 0;
}