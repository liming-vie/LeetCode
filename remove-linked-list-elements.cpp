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
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val)
            head = head->next;
        
        ListNode *move=head, *pre=NULL;
        while (move) {
            if (move->val==val) {
                pre->next=move->next;
            } else {
                pre=move;
            }
            move=move->next;
        }
        
        return head;
    }
};