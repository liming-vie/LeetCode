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
    ListNode* swapPairs(ListNode* head) {
        ListNode *pre=NULL, *move=head, *next=NULL;
        head = NULL;
        while (move && move->next) {
            if (!head)  head = move->next;
            next=move->next->next;
            move->next->next = move;
            if (pre)    pre->next = move->next;
            move->next = next;
            pre=move;
            move=next;
        }
        
        return head ? head : move ;
    }
};