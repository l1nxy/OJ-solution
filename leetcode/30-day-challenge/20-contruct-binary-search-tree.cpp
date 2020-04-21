#include <iostream>
#include <vector>

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
  public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.empty())
            return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        if (preorder.size() == 1)
        {
            root->left = nullptr;
            root->right = nullptr;
            return root;
        }
        int i = 0;
        for (i = 1; i < preorder.size(); i++)
        {
            if (preorder[i] > preorder[0])
                break;
        }
        vector<int> left(preorder.begin() + 1, preorder.begin() + i);
        vector<int> right(preorder.begin() + i , preorder.end());
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        return root;
    }
};
int main()
{
    vector<int> v = {8, 5, 1, 7, 10, 12};
    Solution s;
    s.bstFromPreorder(v);
}
