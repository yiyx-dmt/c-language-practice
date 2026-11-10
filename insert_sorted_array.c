#include<stdio.h>

int main()
{
    int a[11] = {1,4,6,9,13,16,19,28,40,100};
    int num,end,temp1,temp2;
    int i,j;

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