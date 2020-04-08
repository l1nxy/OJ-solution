#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    vector<int> printNumbers(int n)
    {
        string cntstr(n, '9');
        long long cnt = stol(cntstr);
        vector<int> v;
        for (auto i = 1; i <= cnt; ++i)
            v.push_back(i);
        return v;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    auto v = s.printNumbers(3);
    for (auto i : v)
        cout << i << endl;
    return 0;
}
