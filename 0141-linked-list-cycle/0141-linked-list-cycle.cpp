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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }
        ListNode* frst=head;
        ListNode* snd=head;

        while(snd && snd->next!=NULL){
            frst=frst->next;
            snd=snd->next->next;
            if(frst==snd)
            {
                return true;
            }

        }
        return false;
        
    }
};