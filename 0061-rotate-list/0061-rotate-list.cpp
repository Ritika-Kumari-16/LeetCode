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
ListNode* tailnew(ListNode* head, int x){
    int count=0;
    while(head){
        count++;
        if(count==x) return head;
        head=head->next;
    }
    return head;
}
    ListNode* rotateRight(ListNode* head, int k) {
        int len=0;
        if(head==NULL || head->next==NULL) return head;
        ListNode* cur=head;
        ListNode* tail=NULL;
        while(cur){
            len++;
            tail=cur;
            cur=cur->next;
        }
        if(k%len==0) return head;
        k=k%len;
        int reqnodeno=len-k;
        ListNode* newtail=tailnew(head,reqnodeno);
        tail->next=head;
        head=newtail->next;
        newtail->next=NULL;
        return head;
    }
};