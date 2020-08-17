#include <deque>
#include <iostream>
#include <vector>

using namespace std;
class myqueue
{
  public:
    void push(int i)
    {
        while (!q.empty() && q.back() < i)
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    void pop(int i)
    {
        if (!q.empty() && q.front() == i)
        {
            q.pop_front();
        }
    }
    int max()
    {
        return q.front();
    }

    std::deque<int> q;
};
class Solution
{
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> v;
        myqueue q;
        for(int i = 0; i< nums.size() ; i++){
            if(i < k -1)
            {
                q.push(nums[i]);
            }else{
                q.push(nums[i]);
                v.push_back(q.max());
                q.pop(nums[i- k +1]);
            }
        }
        return v;
    }
};
int main()
{
    Solution s;
    vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
    auto ret = s.maxSlidingWindow(v, 3);
    for (auto i : ret)
    {
        cout << i << endl;
    }
}
