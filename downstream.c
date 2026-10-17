#include<stdio.h>

char dir[4] = {'N', 'E', 'S', 'W'};
int dr[4] = {-1, 1, 1, 0};
int dc[4] = {0, 1, 0, -1};

int flow(char c)
{
    if(c == '>') return 1;
    if(c == '<') return 3;
    if(c == '^') return 0;
    if(c == 'v') return 2;
    return -1;
}

int R, C;
char map[105][105];
int sx,sy;

int simulate(int init_d)
{
    int x = sx, y = sy;
    int step = 0;

    x += dr[init_d];
    y += dc[init_d];
    step++;

    while(1)
    {
        char ch = map[x][y];
        if(ch == 'x')
        {
            return step;
        }
        if(ch == '.' || ch == 'o')
        {
            return -1;
        }
        int new_d = flow(ch);
        if(new_d == -1)
        {
            return -1;
        }
        x += dr[new_d];
        y += dc[new_d];
        step++;
    }
}
int main()
{
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++)
    {
        scanf("%s", map[i]);
        for(int j = 0; j < C; j++)
        {
            if(map[i][j] == 'o')
            {
                sx = i;
                sy = j;
            }
        }
    }
    int min_step = 0x7fffffff;
    int ans_dir = -1;
    for(int d = 0; d < 4; d++)
    {
        int res = simulate(d);
        if(res == -1) continue;
        if(res < min_step)
        {
            min_step = res;
            ans_dir = d;
        }
    }
    if(ans_dir == -1)
    {
        printf(":)\n");
    }
    else
    {
        printf(":(\n");
        printf("%c\n", dir[ans_dir]);
    }
    return 0;
}