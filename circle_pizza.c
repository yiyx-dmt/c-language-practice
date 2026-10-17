#include<stdio.h>
#include<stdlib.h>

int cmp(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}
int main()
{
    int N;
    int point[200001];
    int current = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        current = (current + num) % 360;
        point[i] = current;
    }
    qsort(point, N, sizeof(int), cmp);

    int max = 0;
    for(int i = 1; i < N;i++)
    {
        int dis = point[i] - point[i - 1];
        if(dis > max)
        {
            max = dis;
        }
    }
    int final = 360 - point[N - 1];
    if(final > max)
    {
        max = final;
    }
    printf("%d\n", max);
    return 0;
}