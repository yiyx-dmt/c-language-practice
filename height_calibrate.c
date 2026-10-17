#include<stdio.h>
int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    int h[1005];
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &h[i]);
    }

    int cost = 1000000000;
    for(int L = 0;L <= 100; L++)
    {
        int R = L + K;
        int sum = 0;

        for(int i = 0;i < N;i++)
        {
            int height = h[i];
            if(height < L)
            {
                sum += (L - height) * (L - height);
            }
            else if(height > R)
            {
                sum += (height - R) * (height - R);
            }
        }
        if(sum < cost)
        {
            cost = sum;
        }
    }
    printf("%d\n", cost);
    return 0;

}