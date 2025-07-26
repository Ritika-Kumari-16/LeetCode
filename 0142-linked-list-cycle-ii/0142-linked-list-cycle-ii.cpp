/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//  class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_map<ListNode*, int> visited;
//         ListNode* current = head;
        
//         while (current != NULL) {
//             if (visited[current] == 1) 
//                 return current;
//             visited[current] = 1;
//             current = current->next;
//         }
//         return NULL;
//     }
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        ListNode *slow = head, *fast = head;

        // Phase 1: detect if a cycle exists
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Phase 2: find the entry point
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;   // start of the cycle
            }
        }
        return nullptr; // no cycle
    }
};
