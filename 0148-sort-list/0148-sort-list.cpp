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
ListNode* mergelist(ListNode* l1 , ListNode* l2){
    ListNode* ptr= new ListNode(0);
    ListNode* cur= ptr;
    while(l1 && l2){
        if(l1->val <=l2->val){
            cur->next=l1;
            l1=l1->next;
        }
        else{
            cur->next=l2;
            l2=l2->next;
        }
        cur=cur->next;
    }
    while(l1){
        cur->next=l1;
        l1=l1->next;
        cur=cur->next;
    }
    while(l2){
        cur->next=l2;
        l2=l2->next;
        cur=cur->next;
    }
    return ptr->next;
}
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode* frst= sortList(head);
        ListNode* sec=sortList(slow);
        return mergelist(frst,sec);
        
    }
};