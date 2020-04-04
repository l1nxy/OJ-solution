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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
class Solution
{
    void aux(vector<vector<int>> &v, queue<TreeNode *> node)
    {
        if (node.empty() == true)
            return;
        queue<TreeNode *> new_node;
        vector<int> new_v;
        while (node.empty() == false)
        {
            auto n = node.front();
            node.pop();
            if (n != nullptr)
            {
                new_v.push_back(n->val);
                if (n->left != nullptr)
                    new_node.push(n->left);
                if (n->right != nullptr)
                    new_node.push(n->right);
            }
        }
        if (new_v.empty() != true)
        {
            v.push_back(new_v);
        }

        aux(v, new_node);
    }

  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ret;
        aux(ret, q);
        return ret;
    }
};
int main(int argc, char *argv[])
{

    return 0;
}
