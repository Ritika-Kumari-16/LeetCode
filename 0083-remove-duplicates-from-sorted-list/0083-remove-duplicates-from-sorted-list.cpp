class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* node = head;
        while(node){
            while(node->next && node->val == node->next->val){
                node->next = node->next->next;
            }
            node = node->next;
        }
        return head;
    }
};