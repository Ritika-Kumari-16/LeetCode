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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head; // Edge case: empty or single-node list
    
    ListNode* odd = new ListNode(-1);  //Intialize odd LL with -1
    ListNode* ptr = odd;           
    
    ListNode* even = new ListNode(-1); //Intialize even LL with -1
    ListNode* ptr2 = even;        
    
    ListNode* temp = head;  //put temp on head
    int count = 1;      //count=1;

    while (temp) {     //Jab tak temp null nhi hota
        if (count % 2 != 0) {
            ptr->next = temp;  // Add to odd list
            ptr = ptr->next;   // Move pointer
        } else {
            ptr2->next = temp; // Add to even list
            ptr2 = ptr2->next; // Move pointer
        }
        temp = temp->next;
        count++;
    }
    //odd= -1->1->5  ptr
    //even= -1->3->7  ptr2
    
    ptr->next = even->next;   // Connect odd list with even list
    ptr2->next = NULL;        // Terminate the even list

    return odd->next;         // Return the new head (skipping the dummy node)
    }
};