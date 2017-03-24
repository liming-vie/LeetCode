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
	// use fast and slow pointer
	ListNode* findMiddle(ListNode*head) {
		ListNode *fast=head, *slow=head;
        while(fast->next && fast->next->next) {
        	fast=fast->next->next;
        	slow=slow->next;
        }
        return slow;
	}
	// merge sort
	ListNode* merge(ListNode*a, ListNode*b) {
		ListNode*head=new ListNode(0);
		ListNode*move=head;
		while(a && b) {
			if(b->val < a->val) {
				move->next=b;
				b=b->next;
			} else {
				move->next=a;
				a=a->next;
			}
			move=move->next;
		}
		move->next=a?a:b;
		return head->next;
	}
	
    ListNode* sortList(ListNode* head) {
    	if(!head || !head->next)	return head;

    	auto middle=findMiddle(head);
    	auto next=middle->next;
    	middle->next=NULL;

    	return merge(sortList(head), sortList(next));
    }
};