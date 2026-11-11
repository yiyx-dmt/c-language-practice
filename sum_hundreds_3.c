#include<stdio.h>
int main()
{  
   int i;
   int sum = 0;
   do{
      scanf("%d",&i);
      if((i/100)%10 == 3){
         sum += i;
      }
   }while(i != 0);




   printf("sum = %d\n",sum);
}