/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
#define mk(a,b) make_pair(a,b)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int, ListNode*> mp;
        for(int i=0; i<lists.size(); ++i)
            if(lists[i]) 
                mp.insert(mk(lists[i]->val, lists[i]));
        ListNode* head=new ListNode(0), *move=head;
        while(!mp.empty()) {
            auto node = mp.begin();
            mp.erase(node);
            move->next=node->second;
            move=move->next;
            if(move->next) mp.insert(mk(move->next->val, move->next));
        }
        return head->next;
    }
};