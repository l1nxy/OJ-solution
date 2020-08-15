#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;
class Solution
{
  public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> s;
        vector<int> v;
        map<int, int> m;
        for(auto n : nums2){
            while(!s.empty() && n > s.top()){
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        while(!s.empty()){
            m[s.top()]  = -1;
            s.pop();
        }
        for(auto n : nums1){
            v.push_back(m[n]);
        }
        return v;
    }
};

int main()
{

    std::vector<int> v1 = {4, 1, 2};
    vector<int> v2 = {1, 3, 4, 2};
    Solution s;
    auto v = s.nextGreaterElement(v1, v2);
    for(auto i : v){
        cout << i <<endl;
    }
}
