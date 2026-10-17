#include<stdio.h>

typedef long long ll;
int main()
{
    ll K;
    scanf("%lld",&K);

    ll x;
    ll y;
    ll z;

    for(z = 1; ;z++)
    {
        ll z5 = z*z*z*z*z;
        if(z5 >= K)
        {
            break;
        }
        ll rest1 = K - z5;

        for(y = 1; ;y++)
        {
            ll y4 = y*y*y*y;
            if(y4 >= rest1)
            {
                break;
            }
            ll rest2 = rest1 - y4;

            for (x = 1; ;x++)
            {
                ll x3 = x*x*x;
                if(x3 > rest2)
                {
                    break;
                }
                if(x3 == rest2)
                {
                    printf("%lld %lld %lld",x,y,z);
                    return 0;
                }
            }
        }
    }
}