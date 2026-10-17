#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);

    int D[1001];
    int i;
    for(i = 1;i <= N;i++)
    {
        scanf("%d",&D[i]);
    }

    int ans = 0;
    int month;
    for(month = 1;month <=N;month++)
    {
        int a = month;
        int b = a % 10;
        int c = 1;

        while(a > 0)
        {
            int d = a % 10;
            if(d != b)
            {
                c = 0;
                break;
            }
            a = a / 10;
        }
        if(c == 0)
        {
            continue;
        }
        int day;
        for(day = 1;day <= D[month];day++)
        {
            int e = day;
            int f = 1;

            while(e > 0)
            {
                int g = e % 10;
                if(g != b)
                {
                    f = 0;
                    break;
                }
                e = e / 10;
            }
            if (f == 1)
            {
                ans = ans + 1;
            }
        }
    }

    printf("%d",ans);
    return 0;
}