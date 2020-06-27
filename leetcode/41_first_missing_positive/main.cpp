#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int firstMissingPositive(vector<int> &nums)
    {
        if (nums.empty())
            return 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i]  != i + 1)
            {
                while (nums[i] != i + 1 && nums[i] > 0 && nums[i] < nums.size() + 1 && nums[i] != nums[nums[i] - 1])
                {
                    std::swap(nums[i], nums[nums[i] - 1]);
                }
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1)
            {
                cout << i + 1 << endl;
                return i + 1;
            }
        }
        cout << nums.size() + 1 << endl;
        return nums.size() + 1;
    }
};
int main()
{
    Solution s;
    vector v = {3, 4, -1, 1};
    s.firstMissingPositive(v);
    return 0;
}
