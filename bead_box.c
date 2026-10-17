#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int cnt[100001] = {0};
    for(int i = 1;i <= N;i++)
    {
        int colour;
        scanf("%d",&colour);
        cnt[colour] = cnt[colour] + 1;
    }
    int sum = 0;
    for(int i = 1;i <= 100000;i++)
    {
        if(cnt[i] % 2 != 0)
        {
            sum++;
        }
    }
    int rest = sum / 2;
    printf("%d",rest);
    return 0;
}