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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1)   return head;
        
        bool first=true;
        ListNode *move=head, *pre=NULL, *tmp, *next, *tail=NULL;
        while(move) {
            tmp=move;
            for(int i=1; i<k && tmp; ++i) 
                tmp=tmp->next;
            if(!tmp)    break;
            
            pre=move;
            move=move->next;    
            tmp=tail;
            tail=pre;
            for(int i=1; i<k; ++i) {
                next=move->next;
                move->next=pre;
                pre=move;
                move=next;
            }
            
            if(first)   head=pre;
            if(tmp) tmp->next=pre;
            first=false;
        }
        if(tail)    tail->next=move;
        return head;
    }
};