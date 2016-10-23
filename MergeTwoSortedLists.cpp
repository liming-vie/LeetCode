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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0), *move=head;
        while(l1 || l2) {
            if (!l2 || (l1 && l1->val < l2->val)) {
                move->next=l1;
                l1=l1->next;
            }
            else {
                move->next=l2;
                l2=l2->next;
            }
            move=move->next;
        }
        return head->next;
    }
};