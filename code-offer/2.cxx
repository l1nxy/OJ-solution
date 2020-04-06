/*
 * 2.cxx
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
	void replaceSpace(char *str,int length) {
         int space_cnt = 0;
         for(auto i = 0; i < length; ++i)
             if(str[i] == ' ') space_cnt++;
        int index = length+space_cnt *2;
        if(index < length) return;
        //str = (char *)realloc(str,index);
        int j = length -1;
        index--;
        while(j >=0 && index >=0)
        {
            if(str[j] == ' ')
            {
                str[index]='0';
                str[index-1]='2';
                str[index-2] = '%';
                index -=3;
                j--;
            }
            else
            {
                str[index--] = str[j--];
            }
        }
	}
};

int main(int argc, char **argv)
{
	Solution s;
    char str[] = "We Are Happy";
    s.replaceSpace(str,12);
    cout << *str <<endl;
    
	return 0;
}

