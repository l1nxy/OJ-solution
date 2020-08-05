#include <iostream>
#include <utility>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};
class Solution
{
  public:
    int maxPathSum(TreeNode *root, int &val)
    {
        if (root == nullptr)
            return 0;
        auto left = maxPathSum(root->left, val);
        auto right = maxPathSum(root->right, val);
        left = std::max(left, 0);
        right = std::max(right, 0);
        auto mid = root->val + left + right;
        auto ret = root->val + std::max(0, std::max(left, right));
        val = std::max(val, std::max(mid, ret));
        return ret;
    }
    int maxPathSum(TreeNode *root)
    {
        int val = INT_MIN;
        maxPathSum(root,val);
        return val;
    }
};
int main()
{
    Solution s;
}
