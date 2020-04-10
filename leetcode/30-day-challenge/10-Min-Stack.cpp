#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() = default;

    void push(int x) {
        _v.push_back(x);
    }

    void pop() {
        _v.pop_back();
    }

    int top() {
        return _v.back();
    }

    int getMin() {
        return *min_element(_v.begin(),_v.end());
    }

    vector<int> _v;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
    vector<int> v;
}
