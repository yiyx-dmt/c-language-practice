#include<stdio.h>
#include<math.h>
typedef long long ll;

int main()
{
    ll K;
    scanf("%lld",&K);

    ll x;
    ll y;
    ll z;
    ll d;

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

            x = round( pow(rest2,1.0/3));
            for(ll d = -2 ; d <=2 ;d++)
            {
                ll nx = x + d;
                if(nx < 1) continue;
                if(nx*nx*nx == rest2)
                {
                    printf("%lld %lld %lld",x,y,z);
                    return 0;
                }
            }
        }
    }
}