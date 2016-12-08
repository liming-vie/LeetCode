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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *move=head, *prev=NULL;
        while(move && move->next) {
            if(move->val==move->next->val) {
                ListNode*tmp=move->next;
                while(tmp->next && tmp->next->val==move->val)
                    tmp=tmp->next;
                if(prev)    prev->next=tmp->next;
                if(move==head)  head=tmp->next;
                move=tmp->next;
            }
            else {
                prev=move;
                move=move->next;
            }
        }
        return head;
    }
};