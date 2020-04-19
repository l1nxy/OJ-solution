#include <iostream>
#include <vector>
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *node = new ListNode(0);
        ListNode *p = node;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        if (l1 != nullptr)
            p->next = l1;
        if (l2 != nullptr)
            p->next = l2;
        return node->next;
    }
};

int main()
{
}
