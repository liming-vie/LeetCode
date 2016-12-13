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
    ListNode* partition(ListNode* head, int x) {
        ListNode *large=new ListNode(0), *lm=large, *small=new ListNode(0), *sm=small;
        ListNode *move=head;
        while(move) {
            if(move->val<x) {
                sm->next=move;
                sm=move;
            }
            else {
                lm->next=move;
                lm=move;
            }
            move=move->next;
        }
        sm->next=large->next;
        lm->next=NULL;
        return small->next;
    }
};