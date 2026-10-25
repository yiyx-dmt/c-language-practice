#include<stdio.h>
#include<stdlib.h>   //引入 abs() 取绝对值函数

int main(void)
{
    int n,k;    // n 决定盘面大小，k 是飞镖数量
    scanf("%d %d",&n,&k);

    long long ans = 0;
    for(int i = 0;i < k;i++){
        int x,y;
        scanf("%d %d",&x,&y);

        int dx = abs(x - n);
        int dy = abs(y - n);
        int d = dx > dy ? dx :dy;

        ans += n - d;
    }
    printf("%lld\n",ans);
    return 0;
}
