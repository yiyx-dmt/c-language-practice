#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        int ans = 0;

        int min = (N + 2) / 3;
        int max = (N - 1) / 2;
        for(int i = min; i <= max; i++)
        {
            int s = N - i;
            int upper = i;
            int lower = (s + 1) / 2;
            
            if(lower < 1)
            {
                lower = 1;
            }
            if(upper >= lower)
            {
                ans = ans + upper - lower +1;
            } 
        }
        printf("%d\n",ans);
    }
    return 0;
}