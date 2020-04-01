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

/*
1 2 4 3
->
1 3 2 4
*/
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto iter_begin = nums.begin();
        auto iter_end = nums.end();
        if(iter_begin == iter_end){
        	return;
        }
        //if(nums.size() == 1) return;
        auto start = iter_end;
        start--;
        while(true){
        	auto last = start--;
        	if(*start < *last){
        		auto riter = iter_end;
        		while(!(*start < *--riter));
        		iter_swap(start, riter);
        		reverse(last,iter_end);
                return;
        	}

        	if(start == iter_begin){
        		reverse(iter_begin,iter_end);
                return;
        	}
        }
    }
};

int main(int argc, char **argv)
{
	Solution s;
    vector<int> v = {2};
    s.nextPermutation(v);
    for(auto i : v) cout<< i <<" ";
    cout<< endl;
	return 0;
}

