#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int isize = text1.size();
        const int jsize = text2.size();
        vector<vector<int>> dp(isize+1,vector<int>(jsize+1,0));
        for(int i = 1; i <=text1.size(); ++i){
            for(int j = 1; j <=text2.size(); ++j){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        for(auto i : dp)
        {
            for(auto j : i)
                cout<< j <<" ";
            cout << endl;
        }
        return dp[isize][jsize];
    }
};
int main(){

    Solution s;
    cout <<s.longestCommonSubsequence("abcde","ace") <<endl;
    return 0;
}
