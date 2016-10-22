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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *node1=head,*node2=head,*prev;
        for(int i=1; i<n; ++i)  node2=node2->next;
        for(;node2->next; prev=node1,node2=node2->next,node1=node1->next);
        if(node1==head) return head->next;
        prev->next=node1->next;
        return head;
    }
};