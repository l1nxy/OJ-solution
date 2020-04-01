/*
 * a.cxx
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
using LL = long long ;
int main(int argc, char **argv)
{
    #ifdef _DEBUG
    freopen("input.txt","r",stdin);
    #endif
    LL t = 0;
    cin>>t;
    while(t--)
    {
    LL a= 0,b = 0;
    cin>>a>>b;
    //cout<<a<<" "<<b<<endl;
    if(a % b == 0) cout<<0<<endl;
    else
        cout<<((a/b)+1) *b - a<<endl;
    }
	return 0;
}

