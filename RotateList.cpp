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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==NULL)    return head;
        
        ListNode*p1=head,*p2=head;
        int len=0;
        while((k--)>0){
            ++len;
            if(p1->next==NULL){
                p1->next=head;
                k%=len;
            }
            p1=p1->next;
        }
        
        while(p1->next != head && p1->next!=NULL){
            p1=p1->next;
            p2=p2->next;
        }
        p1->next=head;
        head=p2->next;
        p2->next=NULL;
        return head;
    }
};