/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 1->2->3->4->5
// 2->1->3->4->5
// 3->2->1->4->5

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    
    // 1->2->3->4->5
    
    auto current = head->next;
    head->next = nullptr;
        
    auto next = current->next;
    current->next = head;
    
    
   while(next != nullptr) {
       
       // maintain reference so we can backreference
       auto prev = current;
       // advance
       current = next;
       // advance
       next = next->next;
       
       // 
       current->next = prev;
       
    };
    
    
    
    return current;
        
        
    }
};
