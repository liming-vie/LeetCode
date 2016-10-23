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
        if(!head || !head->next)   return head;
        ListNode*move=head,*pre=NULL,*next;
        head=head->next;
        while(move && move->next) {
            next=move->next;
            if(pre) pre->next=next;
            move->next=next->next;
            next->next=move;
            pre=move;
            move=move->next;
        }
        return head;
    }
};