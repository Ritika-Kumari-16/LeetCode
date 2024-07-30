/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL||head->next==NULL ) return head;
        ListNode* slowpt=head;
        ListNode* fastpt= head;
        while(fastpt != nullptr && fastpt ->next!= nullptr ){
            slowpt=slowpt->next;
            fastpt=fastpt->next->next;
        }
        return slowpt;
    }
};