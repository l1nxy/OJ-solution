#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int subarraySum(vector<int> &nums, int k)
    {
        int res = 0;
        int sum = 0;
        unordered_map<int, int> sum_map = {{0,1}};
        for (auto i : nums)
        {
            sum += i;
            res += sum_map[sum-k];
            ++sum_map[sum];
        }
        return res;
    }
};
int main()
{
}
