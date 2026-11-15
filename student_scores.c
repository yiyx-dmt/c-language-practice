#include<stdio.h>

float score[10][5];
float a_stu[10];
float a_cour[5];
//int r,c;

void input_stu(void);
void aver_stu(void);
void aver_cour(void);

int main()
{
    int i,j;
    input_stu();
    aver_stu();
    aver_cour();
    for(i = 0;i < 10;i++){
        printf("NO %2d",i+1);
        for(j = 0;j < 5;j++){
            printf("%8.2f",score[i][j]);
        }
        printf("%8.2f\n",a_stu[i]);
    }
    printf("\naverage:");
    for(j = 0;j < 5;j++){
        printf("%8.2f",a_cour[i]);
    }
    printf("\n");
}

void input_stu(void)
{
    int i,j;
    for(i = 0;i < 10;i++){
        for(j = 0;j < 5;j++){
            scanf("%f",&score[i][j]);
        }
    }
}

void aver_stu(void)
{
    int i,j;
    float s = 0;
    for(i = 0;i < 10;i++){
        for(j = 0;j < 5;j++){
            s += score[i][j];
        }
        a_stu[i] = s / 5.0;
    }
}

void aver_cour(void)
{
    int i,j;
    float s = 0;
    for(j = 0;j < 5;j++){
        for(i = 0;i < 5;i++){
            s += score[i][j];
        }
        a_cour[j] = s / 10.0;
    }
}