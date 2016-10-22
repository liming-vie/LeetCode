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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *move=head, *pre=NULL, *cur=head;
        int vi=1;
        while((vi++)<n)
            move=move->next;
        
        while(move->next) {
            move=move->next;
            pre=cur;
            cur=cur->next;
        }
        if(cur==head)   return head->next;
        
        pre->next=cur->next;
        return head;
    }
};