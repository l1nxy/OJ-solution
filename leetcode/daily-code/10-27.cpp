#include <vector>
#include <queue>
#include <stack>

using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> q;
        vector<int> ret;
        if(root == nullptr){
            return ret;
        }
        q.push(root);
        while(!q.empty()){
          auto * node  = q.top();
            ret.push_back(node->val);
            q.pop();
            if(node->right != nullptr) q.push(node->right);
            if(node->left != nullptr) q.push(node->left);
        }
        return ret;
    }
};
int main(){

}
