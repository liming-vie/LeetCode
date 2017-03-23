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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* nhead=new ListNode(0); // for sorted part
        ListNode *move=head, *tmp, *next;
        while(move) {
        	next=move->next;
        	tmp=nhead;
        	while(tmp->next && tmp->next->val < move->val)
        		tmp=tmp->next;
        	move->next=tmp->next;
        	tmp->next=move;
        	move=next;
        }
        return nhead->next;
    }
};