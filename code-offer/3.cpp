#include <bits/stdc++.h>

using namespace std;
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
           vector<int> v;
        while(head != nullptr)
        {
            v.push_back(head->val);
            head = head->next;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
int main(int argc, char *argv[])
{


    return 0;
}
