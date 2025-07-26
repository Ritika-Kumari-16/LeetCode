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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || (head->next==NULL && n==1)) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(n>0 && fast){
            fast=fast->next;
            n--;
        }
        if(fast==NULL) return head->next;
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* todel=slow->next;
        slow->next=slow->next->next;
        delete(todel);
        return head;
        
    }
};