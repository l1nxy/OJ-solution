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
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        auto head1 = head;
        while(k != 0 && head1 != nullptr)
        {
            k--;
            head1 = head1->next;
        }
        while(head1 !=nullptr &&head != nullptr)
        {
            head1= head1->next;
            head = head->next;
        }
        return head;
    }
};
int main()
{
}
