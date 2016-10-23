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
    ListNode* reverseList(ListNode* head) {
        if(!head)   return NULL;
        ListNode* pre=NULL, *move=head, *next=move->next;
        while(move) {
            move->next=pre;
            pre=move;
            move=next;
            if(next)    next=next->next;
        }
        return pre;
    }
};