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
        if(!head)   return NULL;
        
        ListNode *move=head->next, *pre=head;
        while(move) {
            if(move->val != pre->val) {
                pre->next=move;
                pre=move;
            }
            move=move->next;
        }
        pre->next=NULL;
        return head;
    }
};