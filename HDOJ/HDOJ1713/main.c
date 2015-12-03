#include <stdio.h>
#include <stdlib.h>

long long gcd(long long m,long long n)
{
    return m==0?n:gcd(n%m,m);
}
long long lcm(long long m,long long n)
{
    return m*n/gcd(m,n);
}
int main()
{
    long long a,b,c,d;
    int num;
    scanf("%d",&num);
    while(num--) {
        scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
        int temp_1=gcd(a,b);
        int temp_2=gcd(c,d);
        a/=temp_1;
        b/=temp_1;
        c/=temp_2;
        d/=temp_2;

        int temp_3=gcd(b,d);
        int temp_4=lcm(a,c);

        int temp_5=gcd(temp_3,temp_4);

        temp_3/=temp_5;
        temp_4/=temp_5;

        if(temp_3!=1)
            printf("%d/%d\n",temp_4,temp_3);
        else
            printf("%d\n",temp_4);
    }

    return 0;
}
