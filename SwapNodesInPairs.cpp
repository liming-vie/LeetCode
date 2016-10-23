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
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL || head->next==NULL)  return head;
        
        ListNode *n0=NULL,*n1=head,*n2=head->next,*n3=head->next->next;
        ListNode*h=n2;
        while(1){
            if(n0)   n0->next=n2;
            n2->next=n1;
            n1->next=n3;
            if(n3==NULL || n3->next==NULL)  break;
            n0=n1;
            n1=n3;
            n2=n3->next;
            n3=n3->next->next;
        }
        return h;
    }
};