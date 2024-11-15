/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node* curr = head;
        while(curr){
            Node* temp = new Node(curr->val);
            Node * nxt=curr->next;
            curr->next=temp;
            temp->next=nxt;
            curr=nxt;

        }
        //deepcopy 
        curr = head;
        while(curr && curr->next){
            if(curr->random==NULL){
                curr->next->random=NULL;
            }
            else{
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        Node* newhead=head->next;
        curr=head;
        Node* temp=newhead;
        while(curr && curr->next){
            curr->next= curr->next==NULL? NULL : curr->next->next;
            temp->next= temp->next==NULL? NULL : temp->next->next;   
            curr=curr->next;
            temp=temp->next;     
            }
            return newhead;
        
    }

};