#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        int ret = 1;
        if(n <= 3)
            return n-1;
        else
        {
            int a = n /3;
            int b = n%3;
            if(b == 0)
                ret = pow(3,a);
            else if(b == 1)
                ret = pow(3,a-1)*4;
            else
                ret = pow(3,a)*b;
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
