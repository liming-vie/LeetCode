/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define SKIP(a, l)  int tmp=l; while(tmp--)   a=a->next;

class Solution {
public:
  int getLen(ListNode *head) {
    int len=0;
    while(head) {
      ++len;
      head=head->next;
    }
    return len;
  }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if(!headA || !headB)  return NULL;
        int lena=getLen(headA);
        int lenb=getLen(headB);
        if(lena>lenb) {
          SKIP(headA, lena-lenb);
        }
        else {
          SKIP(headB, lenb-lena);
        }
        while(headA && headA != headB) {
          headA=headA->next;
          headB=headB->next;
        }
        return headA;
    }
};