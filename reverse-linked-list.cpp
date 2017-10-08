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
        ListNode *pre=NULL, *move=head, *next;
        while (move) {
            next = move->next;
            move->next = pre;
            pre = move;
            move = next;
        }
        return pre;
    }
};