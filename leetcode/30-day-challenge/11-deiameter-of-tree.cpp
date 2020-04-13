#include <iostream>
using namespace std;

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
    pair<int, int> dfs(TreeNode *root)
    {
        if (root == nullptr)
            return {0, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        auto d = max({left.first, right.first, left.second + right.second});
        return {d, max(left.second, right.second) + 1};
    }

  public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        return dfs(root).first;
    }
};

int main()
{
}
