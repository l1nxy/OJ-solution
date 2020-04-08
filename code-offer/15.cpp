#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int myPow(long long x, int n, long long m)
{
    if (n == 0)
        return 1 % m;
    long long u = myPow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1)
        u = (u * x) % m;
    return u;
}
  public:
    int cuttingRope(int n)
    {
        long long m = 1e9 + 7;
        int ret = 1;
        if (n <= 3)
            return n - 1;
        else
        {
            int a = n / 3;
            int b = n % 3;
            if (b == 0)
                ret = myPow(3, a, m);
            else if (b == 1)
                ret = ((myPow(3, a - 1, m)%m) * 4) % m;
            else
                ret = (myPow(3, a, m) * b) % m;
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
