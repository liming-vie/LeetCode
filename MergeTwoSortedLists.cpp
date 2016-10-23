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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL)    return l2;
        if(l2==NULL)    return l1;
        
        ListNode *n1=l1,*n2=l2,*newlist,*head;
        if(l1->val > l2->val){
            head=l2;    
            n2=n2->next;
        } 
        else{
            head=l1;  
            n1=n1->next;
        }    
        newlist=head;
        newlist->next=NULL;
        while(n1 && n2){
            if(n1->val < n2->val){
                newlist->next = n1;
                n1=n1->next;
            }
            else{
                newlist->next = n2;  
                n2=n2->next;
            } 
            newlist=newlist->next;
            newlist->next=NULL;
        }
        if(n1)  newlist->next=n1;
        if(n2)  newlist->next=n2;
        
        return head;
    }
};