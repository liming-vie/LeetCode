/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<RandomListNode*, RandomListNode*> mp;
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)   return NULL;
        if(mp.find(head)!=mp.end()) return mp[head];
        
        auto cur = new RandomListNode(head->label);
        mp[head]=cur;
        cur->next=copyRandomList(head->next);
        cur->random=copyRandomList(head->random);
        return cur;
    }
};