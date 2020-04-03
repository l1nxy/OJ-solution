/*
 * main.cxx
 * 
 * Copyright 2020 linxy <l1nxy.zy@gmail.com>
 * 
 * 
 */


#include <bits/stdc++.h>

using namespace std;

class Solution {
    
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ret,maxloc,minloc;
        ret = maxloc = minloc = nums[0];
        for(size_t i = 1; i < nums.size(); i++)
        {
            int temp = maxloc;
            maxloc = max(max(maxloc*nums[i],minloc*nums[i]),nums[i]);
            minloc = min(min(temp*nums[i],minloc*nums[i]),nums[i]);
            ret = max(ret,maxloc);
        }
        return ret;
    }
};


int main(int argc, char **argv)
{
    Solution s;
    vector<int> nums = {2,3,-2,4,5};
    cout << s.maxProduct(nums) << endl;
    
	return 0;
}

