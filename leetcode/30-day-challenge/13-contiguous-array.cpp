#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int findMaxLength(vector<int> &nums)
    {
        if(nums.empty() == true) return 0;
        int ret = 0;
        unordered_map<int, int> m;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += (nums[i] == 1 ? 1 : -1);
            if (sum == 0)
                ret = i + 1;
            else if (m.count(sum))
            {
                ret = max(ret, i - m[sum]);
            }
            else
            {
                m[sum] = i;
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> v = {0, 1, 0, 1};
    cout << s.findMaxLength(v) << endl;
    return 0;
}
