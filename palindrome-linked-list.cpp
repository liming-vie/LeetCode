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
    bool isPalindrome(ListNode* head) {
        if (!head)  return true;
        int len=0;
        ListNode *slow=head, *fast=head;
        while (fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *move=slow->next, *pre=NULL, *next;
        slow->next=NULL;
        while (move) {
            next=move->next;
            move->next=pre;
            pre=move;
            move=next;
        }
        
        ListNode *n1=head, *n2=pre;
        while (n1 && n2) {
            if (n1->val != n2->val) return false;
            n1=n1->next;
            n2=n2->next;
        }
        return true;
    }
};