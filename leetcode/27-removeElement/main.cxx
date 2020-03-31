/*
 * main.cxx
 * 
 * Copyright 2020 linxy <l1nxy.zy@gmail.com>
 * 
 */


#include <bits/stdc++.h>

using std::vector;
using std::size_t;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		
		//if(nums.size() == 0) return 0;

		int len = 0;
		for(size_t i = 0; i < nums.size();++i)
		{
			if(nums[i] != val)
			{
				nums[len++] = nums[i];
			}
		}
		auto vi = nums.begin();
		std::advance(vi,len);
		nums.erase(vi,nums.end());
		//nums.erase(std::remove(nums.begin(),nums.end(),val),nums.end());
		#ifdef _DEBUG
		for(auto i : nums){
		std::cout<< i <<std::endl;
		}
		#endif
        return len;
    }
};

int main(int argc, char **argv)
{
	
	//#ifdef _DEBUG
	//freopen("input.txt","r",stdin);
	//#endif
	
	Solution s;
	vector<int> nums = {0,1,2,2,3,0,4,2};
	std::cout<<s.removeElement(nums,2);
	return 0;
}

