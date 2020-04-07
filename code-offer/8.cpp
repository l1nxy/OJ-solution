#include <bits/stdc++.h>
using namespace std;

using LL = long long;
class Solution
{
  public:
    int Fibonacci(int n)
    {
        LL a[40];
        a[0] = 0;
        a[2] = 1;
        a[1] = 1;
        for (auto i = 3; i < 41; i++)
            a[i] = a[i - 1] + a[i - 2];
        return (int)a[n];
    }
};
int main(int argc, char *argv[])
{

    return 0;
}
