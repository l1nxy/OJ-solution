#include <bits/stdc++.h>

using namespace std;

// Solution 1
/*
class Solution
{
  public:
    bool backspaceCompare(string S, string T)
    {
        stack<char> str;
        stack<char> tr;
        for (auto i : S)
        {
            if (i == '#')
            {
                if (str.empty() != true)
                    str.pop();
            }
            else
            {
                str.push(i);
            }
        }
        for (auto i : T)
        {

            if (i == '#')
            {

                if (tr.empty() != true)
                    tr.pop();
            }
            else
            {
                tr.push(i);
            }
        }
        string s1;
        while(str.empty()!= true)
        {
            auto ch = str.top();
            s1.push_back(ch);
            str.pop();
        }
        string t1;
        while(tr.empty()!= true)
        {
            auto ch = tr.top();
            t1.push_back(ch);
            tr.pop();
        }
        return t1 == s1;
    }
};
*/
class Solution
{
  public:
    // a#b#     c#b#
    bool backspaceCompare(string S, string T)
    {
        size_t i = S.size() - 1;
        size_t j = T.size() - 1;
        int skipS = 0;
        int skipT = 0;
        while (i >= 0 || j >= 0)
        {
            while (i >= 0)
            {
                if (S[i] == '#')
                {
                    skipS++;
                    i--;
                }
                else if (skipS > 0)
                {
                    skipS--;
                    i--;
                }
                else
                    break;
            }
            while (j >= 0)
            {
                if (T[j] == '#')
                {
                    skipT++;
                    j--;
                }
                else if (skipT > 0)
                {
                    skipT--;
                    j--;
                }
                else
                    break;
            }

            if (i >= 0 && j >= 0 && S[i] != T[j])
            {
                return false;
            }
            if ((i >= 0) != (j >= 0))
                return false;
            i--;
            j--;
        }
        return true;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    cout << s.backspaceCompare("a#c", "b") << endl;
    return 0;
}
