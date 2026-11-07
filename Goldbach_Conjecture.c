#include<stdio.h>
int prime(int n);
int f(int i);

int main()
{
    int even_num;
    printf("请输入一个偶数：");
    scanf("%d",&even_num);

    if(even_num <= 2 || even_num % 2 != 0){
        printf("输入错误!请输入大于2的偶数。\n");
        return 1;
    }

    int small_prime = f(even_num);
    if(small_prime != 0){
        int large_prime = even_num - small_prime;
        printf("成功拆分:%d = %d + %d\n",even_num,small_prime,large_prime);
    }else{
        printf("没有找到符合条件的素数对。\n");
    }

    return 0;
}

int prime(int n) /* 判断素数，如果是素数返回1，不是素数则返回0 */
{  
    int i;
    if(n <= 1){
        return 0;
    }
    for(i = 2;i < n;i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

int f(int i) /* 将偶数i表示为两个素数之和，返回其中较小的素数*/
{  
    int j;
    //从2开始找，找到i的一半
    for(j = 2;j <= i/2;j++){
        if(prime(j) == 1 && prime(i-j) == 1){
            return j;
        }
    }
    return 0;

}