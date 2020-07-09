#include <iostream>
#include <vector>

using namespace std;
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int reach = 0;
        for(int i = 0; i< n -1; i++)
        {
            if(i > reach || reach >= n-1) break;
            reach = max(reach, i + nums[i]);
        }
        return reach >= n-1;
    }

};

int main()
{
    Solution s;
    std::vector<int> v ={2,3,1,1,4};
    cout << s.canJump(v) <<std::endl;
}
