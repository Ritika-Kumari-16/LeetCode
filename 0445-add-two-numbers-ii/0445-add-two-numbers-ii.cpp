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
        string s1="";
        string s2="";
        while(l1){
            s1+=l1->val;
            l1=l1->next;

        }
        while(l2){
            s2+=l2->val;
            l2=l2->next;

        }
        int n=s1.size()-1;
        int m=s2.size()-1;
        int carry=0;
        int sum=0;
        ListNode* ans= new ListNode(0);
        while(n>=0 || m>=0){
            sum=carry;
            if(n>=0){
                sum+=s1[n];
                n--;
            }
            if(m>=0){
                sum+=s2[m];
                m--;
            }
            ans->val=sum%10;
            carry=sum/10;
            ListNode* temp=new ListNode(carry);
            temp->next=ans;
            ans=temp;
        }
        if(carry==1){
            return ans;
        }
        else return ans->next;
        
    }
};