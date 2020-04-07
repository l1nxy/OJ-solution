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

class Codec
{
  public:
    int depth_aux(TreeNode *root)
    {
        return root == nullptr ? 0 : max(depth_aux(root->left), depth_aux(root->right)) + 1;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "";
        queue<TreeNode *> n;
        int depth = depth_aux(root);
        n.push(root);
        string v = "[";
        int depth1 = 1;
        while (n.empty() != true)
        {
            int len = n.size();
            for (auto i = 0; i < len; ++i)
            {
                TreeNode *node = n.front();
                if (node != root)
                {
                    v.append(",");
                }
                if (node != nullptr)
                {
                    v.append(to_string(node->val));
                }
                else
                {
                    v.append("null");
                }
                n.pop();

                if (depth1 < depth)
                {
                    if (node != nullptr)
                    {
                        n.push(node->left);
                        n.push(node->right);
                    }
                }
            }
            depth1++;
        }
        v.append("]");
        return v;
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty() == true)
            return nullptr;
        vector<string> v;
        queue<TreeNode *> q;
        int i = 1;
        while (i < data.size() - 1)
        {
            if (data[i] != ',')
            {
                string str;
                int j = i;
                int size = 0;
                while (data[j] != ',' && j < data.size() - 1)
                {

                    str.push_back(data[j++]);
                    size++;
                }
                str[size] = '\0';
                i = j;
                v.push_back(str);
            }
            else
            {
                i++;
            }
        }
        TreeNode *root = nullptr;
        if (v.empty() != true)
        {
            root = new TreeNode(stoi(v[0]));
            q.push(root);
        }
        else
        {
            return nullptr;
        }
        int k = 1;
        while (k < v.size())
        {
            TreeNode *node = q.front();
            q.pop();
            if (v[k] == "null")
                node->left = nullptr;
            else
            {
                node->left = new TreeNode(stoi(v[k]));
                node->left->left = nullptr;
                node->left->right = nullptr;
                q.push(node->left);
            }
            k++;

            if (v[k] == "null")
                node->right = nullptr;
            else
            {
                node->right = new TreeNode(stoi(v[k]));
                node->right->left = nullptr;
                node->right->right = nullptr;
                q.push(node->right);
            }
            k++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

void print(TreeNode *root)
{
    if (root == nullptr)
        return;
    else
        cout << root->val << endl;
    print(root->left);
    print(root->right);
}
int main(int argc, char *argv[])
{

    TreeNode *root = new TreeNode(1);
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(3);
    root->left = nullptr;
    root->right = t1;
    t1->left = t2;
    t1->right = nullptr;
    t2->left = nullptr;
    t2->right = nullptr;
    Codec c;
    string str = c.serialize(root);
    auto new_tree = c.deserialize(str);
    print(new_tree);
    delete root;
    delete t1;
    delete t2;
    return 0;
}
