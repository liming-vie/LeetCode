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
    void reorderList(ListNode* head) {
        // get total length
        int len=0;
        ListNode* move=head;
        while(move) move=move->next, ++len;
        // get the head of second half 
        len=(len+1)>>1;
        ListNode *latter=head;
        while(len--)    latter=latter->next;
        // reverse the second half list
        ListNode *lpre=NULL, *lnext, *stop=latter;
        while(latter) {
            lnext=latter->next;
            latter->next=lpre;
            lpre=latter;
            latter=lnext;
        }
        latter=lpre;
        // merge
        ListNode *next;
        move=head;
        while(latter && move != stop) {
            next=move->next;
            lnext=latter->next;
            move->next=latter;
            latter->next=next;
            move=next;
            latter=lnext;
        }
        if(move) move->next=NULL;
    }
};