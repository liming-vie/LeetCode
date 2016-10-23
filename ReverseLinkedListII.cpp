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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode*pre=NULL, *move=head;
        for(int i=1; i<m; ++i) {
            pre=move;
            move=move->next;
        }
        ListNode *p=pre, *q=move, *next;
        pre=move;
        move=move->next;
        for(int i=m; i<n; ++i) {
            next=move->next;
            move->next=pre;
            pre=move;
            move=next;
        }
        if(p)   p->next=pre;
        q->next=move;
        return m==1?pre:head;
    }
};