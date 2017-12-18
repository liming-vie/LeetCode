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
        
        ListNode *even_head=head->next, *odd_move=head, *even_move=even_head;
        ListNode *move = even_head->next, *next;
        bool is_odd=true;
        while (move) {
            next = move->next;
            if (is_odd) {
                odd_move->next = move;
                odd_move = odd_move->next;
            } else {
                even_move->next = move;
                even_move = even_move->next;
            }
            is_odd = !is_odd;
            move = next;
        }
        
        odd_move->next = even_head;
        even_move->next = NULL;
        
        return head;
    }
};