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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode*n1=l1,*n2=l2;
        ListNode *res,*head;
        int t=0;
        int sum=n1->val + n2->val;
        t=sum/10;
        sum%=10;
        res=new ListNode(sum);
        head=res;
        while(n1->next && n2->next){
            sum=n1->next->val + n2->next->val +t;
            t=sum/10;
            sum%=10;
            res->next = new ListNode(sum);
            res=res->next;
            n1=n1->next;
            n2=n2->next;
        }
        while(n1->next){
            sum = n1->next->val + t;
            t=sum/10;
            sum%=10;
            res->next = new ListNode(sum);
            res=res->next;
            n1=n1->next;
        }
        while(n2->next){
            sum=n2->next->val + t;
            t=sum/10;
            sum%=10;
            res->next = new ListNode(sum);
            res=res->next;
            n2=n2->next;
        }
        if(t){
            res->next = new ListNode(t);
        }
        return head;
    }
};