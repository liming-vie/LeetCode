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
        if(!head)   return NULL;
        // count node number
        ListNode* move=head;
        int count=1;
        while(move->next) {
            ++count;
            move=move->next;
        }
        
        k%=count;
        // move to the end
        move=head;
        count=k;
        while(count--){
            move=move->next;
        }
        ListNode* cur=head;
        while(move->next) {
            move=move->next;
            cur=cur->next;
        }
        // rotate
        move->next=head;
        head=cur->next;
        cur->next=NULL;
        
        return head;
    }
};