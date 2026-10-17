#include<stdio.h>

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main()
{
    int H,W;
    char map[1001][1001];
    scanf("%d %d",&H,&W);
    getchar();

    for(int i = 0;i < H;i++)
    {
        scanf("%s",map[i]);
    
    }
    for(int i = 0;i < H;i++)
    {
        for(int j = 0;j < W;j++)
        {
            if(map[i][j] == '#')
            {
                printf("#");
            }
            else
            {
                int bomb = 0;
                for(int k = 0;k < 8;k++)
                {
                    int nx = i +dx[k];
                    int ny = j +dy[k];
                    if(nx >= 0 && nx < H && ny >=0 && ny < W)
                    {
                        if(map[nx][ny] == '#')
                        {
                            bomb++;
                        }
                    }
                }
                printf("%d",bomb);
            }
        }
        printf("\n");
    }
    return 0;
}