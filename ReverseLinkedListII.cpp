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
        ListNode*node=head,*prev=NULL,*next=head->next,*pprev=NULL;
        int curn=1;
        ++m;
        while(node && curn<m){
            pprev=prev;
            prev=node;
            node=next;
            if(node)    next=node->next;
            ++curn;
        }
        ListNode*nodem=prev;
        while(node && curn++<=n){
            node->next=prev;
            prev=node;
            node=next;
            if(node)    next=node->next;
        }
        if(nodem)   nodem->next=node;
        if(m==2)    head=prev;
        else    pprev->next=prev;
        return head;
    }
}; 