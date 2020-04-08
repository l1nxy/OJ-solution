#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
class Solution
{
  public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        auto root = head;
        auto pre = head;
        if (root->val == val)
        {
            head = head->next;
            return head;
        }

        if (root != nullptr && root->next != nullptr)
            root = root->next;
        while(root != nullptr && root->val != val)
        {
            root = root->next;
            pre = pre->next;
        }
        if(root != nullptr)
        {
            pre->next  = root->next;
        }
        else{
            return nullptr;
        }
        return head;
    }
};
int main(int argc, char *argv[])
{

    return 0;
}
