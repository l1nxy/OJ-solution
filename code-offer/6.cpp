#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    void pop_aux(stack<int> &s1,stack<int> &s2)
    {
        while(s1.empty() != true)
        {
            int x = s1.top();
            s1.pop();
            s2.push(x);
        }
    }
    int pop() {
        int ret = 0;
        pop_aux(stack1,stack2);
        ret = stack2.top();
        stack2.pop();
        pop_aux(stack2,stack1);
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
int main(int argc, char *argv[])
{

    Solution s;
    for(auto i =0; i< 100; ++i)
        s.push(i);
    for(auto i = 0 ; i< 100;++i)
        cout<< s.pop()<<endl;
    return 0;
}
