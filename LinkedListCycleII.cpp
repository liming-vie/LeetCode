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
    ListNode *detectCycle(ListNode *head) {
        ListNode *m1=head, *m2=head;
        bool cycle=false;
        while(m1 && m2 && m2->next) {
        	m1=m1->next;
        	m2=m2->next->next;
        	if(m1==m2)	{
        		cycle=true;
        		break;
        	}
        }
        if(!cycle)	return NULL;

        m1=head;
        while(m1!=m2) {
        	m1=m1->next;
        	m2=m2->next;
        }
        return m1;
    }
};