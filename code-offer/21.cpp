#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        while(i < j)
        {
            while(i <  j && nums[i] % 2 == 1)
                i++;
            while(i< j&& nums[j] %2 ==0)
                j--;
            swap(nums[i],nums[j]);
        }
        return nums;
    }
};
int main()
{
   Solution s;
   vector<int> v = {2,4,6};
   auto t = s.exchange(v);
   for(auto  i:t)
       cout<< i<<endl;
}
