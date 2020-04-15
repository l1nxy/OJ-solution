#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
  public:
    string stringShift(string s, vector<vector<int>> &shift)
    {
        int i = 0;
        for (auto x : shift)
        {
            int t = 0;
            if (x[0] == 0)
            {
                t = x[1] * -1;
            }
            else
            {
                t = x[1];
            }
            i += t;
        }
        string ret;
        cout << i<<endl;

        if (i < 0)
        {
            i = (abs(i)% s.size());
            ret = s.substr(i, s.size()) + s.substr(0, i);
        }
        else
        {
            i = i % s.size();
            ret = s.substr(s.size() - i, i) + s.substr(0, s.size() - i);
        }
        cout << ret << endl;
        return ret;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v ={{0,6},{1,2}};
    cout << s.stringShift("wpdhhcj", v) <<endl;
}
