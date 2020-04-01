/*
 * b.cxx
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

using ll = long long ;
int main(int argc, char **argv)
{
    #ifdef _DEBUG
    freopen("input.txt","r",stdin);
    #endif
	ll t = 0;
	cin >> t;
	while(t--)
	{
		int n,k;
        cin >> n >> k;
        int x = n - 2;//before
        int y = n - 1;//after
        //cout<< n << k <<endl;
        while(--k){
            if(x == y-1)
            {
                x--;
                y = n-1;
            }
            else
            {
                y--;
            }
        }
       // cout<<x << y <<endl;
        for(auto i = 0; i< n; ++i)
            {
                if(i == x || i == y)
                {
                    cout<<'b';
                }
                else
                {
                    cout<<'a';
                }   
            }
            cout<<endl;
	}
	return 0;
}

