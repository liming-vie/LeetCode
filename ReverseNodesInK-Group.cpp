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
ListNode *reverseKGroup(ListNode *head, int k) {
  if(k<=1)    return head;
  int len=0;
  ListNode*move=head;
  while(move){
      ++len;
      move=move->next;
  }
  
  ListNode*h=head,*n0=head,*last=NULL,*prev,*next,*tmp;
  while(k<=len){
      len-=k;
      tmp=n0;
      for(int i=k-1; i>0; --i){
          int t=i;
          move=n0;
          prev=last;
          n0=n0->next;
          while(t--){
              if(prev)    prev->next=move->next;
              prev=move->next;
              next=prev->next;
              prev->next=move;
              move->next=next;
          }
      }
      if(h==head) h=n0;
      last=tmp;
      n0=last->next;
  }
  return h;
}
};