#include <bits/stdc++.h>

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

void print_v(vector<int> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}
class Solution
{
    TreeNode *aux(vector<int> pre, vector<int> vin)
    {
        cout << "pre:";
        print_v(pre);
        cout << "vin:";
        print_v(vin);
        if (pre.empty() == true || vin.empty() == true)
        {
            return nullptr;
        }
        int head = pre[0];
        int head_vin = 0;
        for (size_t i = 0; i < vin.size(); ++i)
        {
            if (vin[i] == head)
            {
                head_vin = i;
                break;
            }
        }
        vector<int> l_vin(vin.begin(), vin.begin() + head_vin);
        vector<int> r_vin(vin.begin() + head_vin + 1, vin.end());
        vector<int> l_pre(pre.begin() + 1, pre.begin() + (head_vin + 1));
        vector<int> r_pre(pre.begin() + head_vin + 1, pre.end());
        TreeNode *root = new TreeNode(head);
        root->left = aux(l_pre, l_vin);
        root->right = aux(r_pre, r_vin);
        return root;
    }

  public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        return aux(pre, vin);
    }
};
int main(int argc, char *argv[])
{
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> in = {4, 7, 2, 1, 5, 3, 8, 6};
    Solution s;
    s.reConstructBinaryTree(pre, in);
    return 0;
}
