#include <iostream>

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
    ListNode *reverseList(ListNode *head)
    {
        auto node = head;
        ListNode *pre = nullptr;
        while(node != nullptr)
        {
            auto temp = node->next;
            node->next = pre;
            pre = node;
            node = temp;
        }
        return pre;
    }
};
int main()
{
}
