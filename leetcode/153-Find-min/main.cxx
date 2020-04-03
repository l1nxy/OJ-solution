/*
 * main.cxx
 * 
 * Copyright 2020 linxy <l1nxy.zy@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        
        while(start < end)
        {
            if(nums[start] < nums[end])
                return nums[start];
            
            int mid = (start + end) /2;
            
            if(nums[mid] >= nums[start]) start = mid +1;
            else end = mid;
        }
        
        return nums[start];
    }
};

int main(int argc, char **argv)
{
	Solution s;
    vector<int> num{10,1,10,10,10};
    cout << s.findMin(num) << endl;
	return 0;
}

