#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v(nums.size(),0);
        stack<int> s;
        for(int i = 2 * nums.size() - 1; i  >= 0;i--){
            while(!s.empty() && s.top() <= nums[i % nums.size()]){
                s.pop();
            }
            auto value = s.empty() ? -1: s.top();
            v[i % nums.size()] = value;
            s.push(nums[i % nums.size()]);
        }
        return v;
    }
};
int main(){
    Solution s;
    vector<int> v = {1,2,1};
    auto v1 = s.nextGreaterElements(v);
    for(auto i : v1){
        cout << i << endl;
    }
}
