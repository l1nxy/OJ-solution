#include <iostream>
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
    bool helper(TreeNode *a, TreeNode *b)
    {
        if (b == nullptr)
            return true;
        if (a == nullptr)
            return false;
        return a->val == b->val && helper(a->left, b->left) && helper(a->right, b->right);
    }

  public:
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (A == nullptr || B == nullptr)
            return false;
        return helper(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};

int main()
{
}
