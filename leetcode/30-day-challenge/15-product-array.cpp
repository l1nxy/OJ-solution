#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ret(nums.size(), 1);
        for (auto i = 1; i < nums.size(); ++i)
        {
            ret[i] = ret[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            ret[i] *= right;
            right *= nums[i];
        }
        return ret;
    }
};
int main()
{
}
