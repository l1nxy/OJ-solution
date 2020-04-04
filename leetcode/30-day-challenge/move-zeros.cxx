/*
 * move-zeros.cxx
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
    void moveZeroes(vector<int>& nums) {
    size_t i = 0;
    int j = 0;//index of non-zero
    while(i < nums.size())
    {
        if(nums[i] !=0){
            nums[j++] = nums[i++];    
        }
        else{
            i++;
        }
    }
    for(size_t k = j; k < nums.size(); ++k) nums[k] =0;
    //for(auto x : nums) cout<< x << " ";
    //cout<< endl;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<int> v ={0,1,0,3,12};
    s.moveZeroes(v);	
	return 0;
}

