/*
 * main.cxx
 * 
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 */


#include <bits/stdc++.h>

using namespace std;


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() = default;

    
    void push(int x) {
        _stack.push_back(x);
    }
    
    void pop() {
         _stack.pop_back();
    }
    
    int top() {
        return _stack.back();
    }
    
    int getMin() {
        return *min_element(_stack.begin(),_stack.end());
    }
    vector<int> _stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char **argv)
{
	MinStack minStack;
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
cout<< minStack.getMin() <<endl;   
minStack.pop();
cout <<minStack.top()<<endl;      
cout<<minStack.getMin()<<endl;;   
	return 0;
}

