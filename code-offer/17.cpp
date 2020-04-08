#include <bits/stdc++.h>
using namespace std;

class Solution
{
    double pow_helper(double x, long long n)
    {
        if (n == 0)
            return 1;
        double ret = pow_helper(x, n / 2);
        ret = ret * ret;
        if (n % 2 == 1)
            ret *= x;
        return ret;
    }

  public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        double ret = 1;
        double abs_x = abs(x);
        long long abs_n = abs((long long)n);
        ret = pow_helper(abs_x, abs_n);
        if (n < 0)
        {
            ret = 1 / ret;
        }
        if (x < 0)
        {
            if (n % 2 == 0)
                return ret;
            else
                return 0 - ret;
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << INT_MIN << " " << INT_MAX<<endl;
    cout << s.myPow(2, INT_MIN) << endl;
    return 0;
}
