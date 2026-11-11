#include<stdio.h>

int main()
{
    int a[11] = {1,4,6,9,13,16,19,28,40,100};
    int num,end,temp1,temp2;
    int i,j;

    printf("请输入要插入的数字:");
    scanf("%d",&num);
    
    end = a[9];
    if(num > end){
        a[10] = num;
    }else{
        for(i = 0;i < 10;i++){
            if(a[i] > num){
                temp1 = a[i];
                a[i] = num;
                for(j = i+1;j < 11;j++){
                    temp2 = a[j];
                    a[j] = temp1;
                    temp1 = temp2;     //更新临时变量，将当前被覆盖的元素值作为下一次后移的数据
                }
                break;
            }
        }
    }
    for(i = 0;i < 11;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}