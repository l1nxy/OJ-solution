#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
  public:
    bool checkValidString(string s)
    {
        stack<int> left;
        stack<int> star;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '*')
            {
                star.push(i);
            }
            else if (s[i] == '(')
            {
                left.push(i);
            }
            else
            {
                if(left.empty() == true && star.empty() == true) return false;
                if(left.empty() == false) left.pop();
                else star.pop();
            }
        }
        while(left.empty() == false && star.empty() == false)
        {
            if(left.top() > star.top()) return false;
            left.pop();
            star.pop();
        }
        return left.empty();
    }
};

int main()
{
    Solution s;
    cout << s.checkValidString("(())((())()()(*)(*()(())())())()()((()())((()))(*") << endl;
}
