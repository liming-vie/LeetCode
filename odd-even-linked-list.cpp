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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)   return head;
        
        ListNode *odd_head = head, *even_head = head->next;
        ListNode *odd_move = head, *even_move = head->next;
        while (odd_move->next->next && even_move->next->next) {
            odd_move->next = odd_move->next->next;
            odd_move = odd_move->next;
            
            even_move->next = even_move->next->next;
            even_move = even_move->next;
        }
        
        if (odd_move->next->next) {
            odd_move->next = odd_move->next->next;
            odd_move = odd_move->next;
        }
        even_move->next = NULL;
        
        odd_move->next = even_head;
        return odd_head;
    }
};