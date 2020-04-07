#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(size_t i = 0; i< nums.size();++i)
        {
            if(nums[i] != i)
            {
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                while(nums[i] != i)
                    swap(nums[i],nums[nums[i]]);
            }
        }
        return -1;
    }
};
int main(int argc, char *argv[])
{
    vector<int> v = {2, 3, 1, 0, 2, 5, 3};
    Solution s;
    cout <<s.findRepeatNumber(v) <<endl;
    return 0;
}
