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
  public:
    TreeNode *mirrorTree(TreeNode *root)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        auto temp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(temp);
        return root;
    }
};
int main()
{
}
