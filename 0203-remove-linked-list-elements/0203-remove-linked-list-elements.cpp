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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        while(head && head->val==val){
            head=head->next;
        }
        ListNode* cur=head;
        while(cur && cur->next!=NULL){
            if(cur->next->val==val){
                ListNode* temp=cur->next;
                cur->next=cur->next->next;
                delete(temp);
            }
            else{
                cur=cur->next;
            }
        }
        return head;
    }
};