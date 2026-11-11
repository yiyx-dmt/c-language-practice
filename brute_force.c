#include<stdio.h>
int main()
{
    int x, y, z,found=0;
    int result = 532;
    
    for(x=1;x<10;x++){
        for(y=1;y<10;y++){
            for(z=1;z<10;z++){
                int xyz=x*100+y*10+z;
                int yzz=y*100+z*10+z;
                if(xyz+yzz==result){
                    found=1;
                    break;
                }
            }
            if(found)break;
        }
        if(found)break;
    }


    printf("x=%d,y=%d,z=%d\n",x,y,z);      
}