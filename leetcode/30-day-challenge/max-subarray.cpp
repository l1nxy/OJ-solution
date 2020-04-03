#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    int ret = nums[0];
    int maxloc = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
      maxloc = max(nums[i] + maxloc, nums[i]);
      ret = max(maxloc, ret);
    }
    return ret;
  }
};
int main() {
    Solution s;
  //vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    std::vector<int> v = {-2,-1};
    cout<< s.maxSubArray(v) << endl;
}
