#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        int ret = 1;
        while(n != 1)
        {
            ret *= (int)sqrt(n);
            n -=(int)sqrt(n);
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    for(auto i = 1 ; i < 60 ; i++)
        cout<<i <<" "<< s.cuttingRope(i) <<endl;
    return 0;
}
