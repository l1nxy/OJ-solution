/*
 * best-time-stock.cxx
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

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int ret = 0;
        for (size_t i = 0; i < prices.size();)
        {
            if (i + 1 < prices.size() && prices[i] < prices[i + 1])
            {

                size_t j = i + 1;
                while (j < prices.size() && prices[j] > prices[j - 1])
                    j++;
                ret += (prices[j - 1] - prices[i]);
                i = j;
            }
            else
            {
                i++;
            }
        }
        return ret;
    }
};
int main(int argc, char **argv)
{

    Solution s;
    vector<int> v = {7, 6, 4, 3, 1};
    cout << s.maxProfit(v) << endl;
    return 0;
}
