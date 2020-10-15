#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Node
{
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL)
    {
    }

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL)
    {
    }

    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next)
    {
    }
};
class Solution
{
  public:
    int depth(Node *root)
    {
        if (root->right != nullptr)
        {
            return 1 + depth(root->right);
        }
        else
        {
            return 1;
        }
    }
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return root;
        queue<Node *> q;
        queue<Node *> temp;
        auto d = depth(root);
        q.push(root);
        for (int i = 0; i < d; ++i)
        {
            while (!q.empty())
            {
                auto *node = q.front();
                temp.push(node->left);
                temp.push(node->right);
                q.pop();
                if (q.empty())
                {
                    node->next = nullptr;
                }
                else
                {
                    node->next = q.front();
                }
            }
            swap(q, temp);
        }
        return root;
    }
};
int main()
{
}
