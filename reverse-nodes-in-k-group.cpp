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
        if (k==1)   return head;
        ListNode *move=head, *next=NULL, *pre=NULL, *ppre=NULL, *pppre=NULL, *nnext=NULL;
        head=NULL;
        int count;
        while (move) {
            count=0;
            nnext=move;
            while (nnext && count<k) {
                ++count;
                nnext=nnext->next;
            }
            if (count!=k) {
                if (pppre)  pppre->next = move;
                break;
            }
            
            ppre=move;
            pre=NULL;
            while (move != nnext) {
                next=move->next;
                move->next=pre;
                pre=move;
                move=next;
            }
            
            if (pppre)   pppre->next=pre;
            if (!head)  head=pre;
            pppre=ppre;
            move=nnext;
        }
        
        return head ? head : move;
    }
};