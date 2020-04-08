#include <bits/stdc++.h>

using namespace std;
class Solution
{
  public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for (auto i = 2; i <= n; i++)
        {
            dp[i] = INT_MAX;
            for (int j = 1; i - j * j >= 0; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    for (auto i = 3; i < 21; i++)
        cout << s.numSquares(i) << endl;
    return 0;
}
