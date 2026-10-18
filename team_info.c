#include<stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);

    char name[35];
    char city[15];
    char date[20];
    int flag;
    for(int i = 1;i <= n;i++)
    {
        scanf("%s %s %s %d",name,city,date,&flag);
        if(flag == 1)
        {
            printf("gdut_%s %s %s\n",name,city,date);
        }
    }
    return 0;
}