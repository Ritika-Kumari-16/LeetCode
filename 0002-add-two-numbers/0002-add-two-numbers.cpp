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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(t1 || t2){
            int sum=carry;
            if(t1){
                sum+=(t1->val);
                t1=t1->next;
            }
            if(t2){
                sum+=(t2->val);
                t2=t2->next;
            }
            ListNode* t= new ListNode(sum%10);
            temp->next=t;
            temp=temp->next;
            carry=sum/10;
        }
        if(carry){
            ListNode* t= new ListNode(carry);
            temp->next=t;
        }
        return ans->next;
    }
};