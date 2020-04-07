#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        int dp[100];
        dp[0]=0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i < 100;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[number];
    }
};
int main(int argc, char *argv[])
{

    return 0;
}
