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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *newlist=NULL, *head=NULL;
        int len=lists.size();
        for(int i=0; i<len; ++i)
            if(lists[i]==NULL){
                len--;
                lists.erase(lists.begin()+i);
                --i;
            }
        if(lists.size()==0)   return NULL;
        if(lists.size()==1)   return lists[0];
        
        multimap<int,int> mp;
        len=lists.size();
        for(int i=0;i<len; ++i)
            mp.insert(make_pair((lists[i])->val,i));
        while(mp.size()>1){
            int i = mp.begin()->second;
            mp.erase(mp.begin());
            if(newlist==NULL){
                newlist=lists[i];
                head=newlist;
            }else{
                newlist->next=lists[i];
                newlist=newlist->next;
            }
            if(lists[i]->next!=NULL){
                lists[i]=lists[i]->next;
                mp.insert(make_pair(lists[i]->val,i));
            }
        }
        newlist->next=lists[(mp.begin())->second];
        return head;
    }
};