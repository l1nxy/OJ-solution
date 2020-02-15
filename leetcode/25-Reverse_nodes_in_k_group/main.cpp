#include <iostream>
#include <string>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
class Solution
{
public:
    ListNode *last = nullptr;
    ListNode *reverseK(ListNode *head, int k)
    {

        if (k == 1)
        {
            last = head->next;
            return head;
        }

        ListNode *newhead = reverseK(head->next, k - 1);
        head->next->next = head;
        head->next = last;
        return newhead;
    }
    int getLen(ListNode *head)
    {
        int size = 0;
        while (head != nullptr)
        {
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode *getNewhead(ListNode *head, int k)
    {
        while (k--)
        {
            head = head->next;
        }
        return head;
    }
    ListNode *moveHeadPre(ListNode *head, int time, int k)
    {
        int total = time * k - 1;
        while (total > 0)
        {
            head = head->next;
            total--;
        }
        return head;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int length = getLen(head);
        if (length < k)
            return head;
        int count = length / k;
        int time = 1;
         ListNode * preHead =nullptr;
        while (count != 0)
        {
            if (time != 1)
            {
                ListNode * newHead = preHead->next;
                ListNode * newreverseHead = reverseK(newHead,k);

                preHead->next = newreverseHead;
                preHead = moveHeadPre(head,time,k);
                time++;
                count--;
            }
            else
            {
                head = reverseK(head,k);
                preHead = moveHeadPre(head,time,k);
                time++;
                count--;
            }

        }

        return head;
    }
};

void test_case()
{
    ListNode l(1);
    ListNode l1(2);
    ListNode l2(3);
    ListNode l3(4);
    ListNode l4(5);
    ListNode l5(6);
    l.next = &l1;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = nullptr;
    print(&l);
    Solution s;
    auto ll = s.reverseKGroup(&l, 2);
    print(ll);
}

int main(int argc, char const *argv[])
{
    test_case();
    return 0;
}
