#include<stdio.h>
int main()
{
    int a=0,b=0;
    //unsigned int a=0,b=0;     //求unsigned的最大数
    while(++a > 0);
    printf("int数据类型最大数是:%d\n",a-1);
    //printf("int数据类型最大数是:%u\n",a-1);   //unsigned输出需要改为%u
    b++;
    while((a = a/10) != 0)
    {
        b++;
    }
    printf("int数据类型最大的数的数位是:%d",b);
    return 0;
}