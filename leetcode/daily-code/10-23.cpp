/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        auto *slow = head;
        auto *fast = head;
        while(fast!= nullptr){
            slow = slow->next;
            fast = fast->next == nullptr ? nullptr:fast->next->next;
        }

        auto *mid = slow;
        ListNode *prev = nullptr;
        while(mid != nullptr)
        {
            auto *temp = mid->next;
            mid->next = prev;
            prev = mid;
            mid = temp;
        }

        while(head && prev){
            if(head->val != prev->val){
                return false;
            }
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};