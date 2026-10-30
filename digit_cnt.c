#include<stdio.h>
#define number 10   //与const那句意义相同

int main()
{
    //const int number = 10;    //10多次出现，是magic number
    int x;
    int count[10] = {0};
    int i;

    // for(i = 0;i < number;i++){
    //     count[i] = 0;
    // }
    scanf("%d",&x);
    while(x != -1){
        if(x>=0 && x<=9){
            count[x] ++;
        }
        scanf("%d",&x);
    }
    for(i = 0;i < number;i++){
        printf("%d:%d\n",i,count[i]);
    }
    return 0;
}