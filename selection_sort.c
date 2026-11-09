#include<stdio.h>
int main()
{
    int i,j,min,temp;
    int a[10];

    printf("enter data:\n");

    for(i = 0;i < 10;i++){
        scanf("%d",&a[i]);
    }
    for(i = 0;i < 10;i++){
        printf("%5d ",a[i]);
    }
    printf("\n");

    for(i = 1;i <= 9;i++){          //外层循环：控制轮数，10个数只需要比9轮
        min = i;                    //假设当前这轮的开头位置i就是最小值的下标
        for(j = i+1;j < 10;j++){    //内层循环：从i的下一个数找起，一直找到最后一个数（第10个）
            if(a[min] > a[j]){
                min = j;            //记录下最小值的位置，即将最小值的下标min更新为j
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    for(i = 0;i < 10;i++){
        printf("%5d ",a[i]);
    }
    printf("\n");

    return 0;
}