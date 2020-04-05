#include <bits/stdc++.h>


using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> _stack;
        vector<int> ret;
        auto p = root;
        while(_stack.empty() == false || p != nullptr)
        {
            while(p!=nullptr)
            {
                _stack.push(p);
                p = p->left;
            }
            if(s.empty() != true)
            {
                p = _stack.top();
                ret.push_back(p->val);
                _stack.pop();
                p = p->right;
            }
        }
        
        return ret;
    }
};

int main()
{

    Solution s;
    s.inorderTraversal()
}
