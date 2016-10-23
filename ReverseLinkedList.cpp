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
        
        ListNode*p=NULL,*move=head,*n;
        while(move){
            n=move->next;
            move->next=p;
            p=move;
            move=n;
        }
        return p;
    }
};