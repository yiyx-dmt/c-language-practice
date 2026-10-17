#include<stdio.h>
int main()
{
    double foot;
    double inch;

    printf("请分别输入身高的英尺与英寸：");
    scanf("%lf %lf",&foot,&inch);

    printf("身高是%lf米。\n",((foot + inch / 12.0 ) * 0.3048));
    return 0;
}
