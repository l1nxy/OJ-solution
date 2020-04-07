#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    int jumpFloorII(int number)
    {
        vector<int> dp(number + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < number + 1; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                dp[i] += dp[i - j];
            }
        }
        return dp[number];
    }
};
int main(int argc, char *argv[])
{

    return 0;
}
