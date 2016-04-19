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
    void func(int*y, int *val) {
        if((*val) > 9){
            *y = 1;
            *val -= 10;
        }else   *y=0;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = l1 ? l1 : l2;
        ListNode *move = head, *prev = nullptr;
        int y=0;
        while(l1 && l2) {
            move->val = l2->val + l1->val + y;
            func(&y, &(move->val));
            prev=move;
            move=move->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1) {
            if(prev)    prev->next = l1;
            move = l1;
        }
        else if(l2) {
            if(prev)    prev->next = l2;
            move = l2;
        }
        
        while(move) {
            move->val += y;
            func(&y, &(move->val));
            prev=move;
            move=move->next;
        }
        
        prev->next = (y?new ListNode(1):nullptr);
        return head;
    }
};