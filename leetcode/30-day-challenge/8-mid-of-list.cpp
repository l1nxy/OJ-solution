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
    ListNode *middleNode(ListNode *head)
    {
        if(head->next  == nullptr)
            return  head;
        auto node2 = head;
        auto node1 = head;
        while(node2 != nullptr && node2->next != nullptr)
        {
            node2 = node2->next->next;
            node1 = node1->next;
        }
        return node1;
    }
};
int main(int argc, char *argv[])
{

    return 0;
}
