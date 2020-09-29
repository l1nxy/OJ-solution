/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        digits.back()++;
        bool need_add = false;
        if (digits.back() < 10)
            return digits;
        else
        {
            digits.back() = 0;
            need_add = true;
        }
        for (auto i = digits.rbegin() + 1; i != digits.rend(); ++i)
        {
            if (need_add == true)
            {
                *i += 1;
                if (*i == 10)
                {
                    *i = 0;
                    need_add = true;
                }
                else
                {
                    need_add = false;
                }
            }
        }
        
        if(need_add){
            digits.front() = 0;
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
// @
