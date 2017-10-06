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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int, ListNode*> mp;
        for(auto list:lists) {
            if (list) {
                mp.insert(make_pair(list->val, list));
            }
        }
        
        ListNode *head = new ListNode(0);
        ListNode *move = head;
        while (!mp.empty()) {
            auto cur = mp.begin();
            if (cur->second->next) {
                mp.insert(make_pair(cur->second->next->val, cur->second->next));
            }
            move->next = cur->second;
            move = cur->second;
            mp.erase(cur);
        }
        
        return head->next;
    }
};