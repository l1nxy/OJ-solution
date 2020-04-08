#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n != 0)
        {
            n = n&(n-1);
            cnt++;
        }
        return cnt;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    cout<<s.hammingWeight(9)<<endl;
    return 0;
}
