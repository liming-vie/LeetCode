/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)  return NULL;
        
        unordered_map<int, UndirectedGraphNode*> mp;
        
        queue<pair<UndirectedGraphNode*, UndirectedGraphNode*>> q;
        UndirectedGraphNode* ret = new UndirectedGraphNode(node->label);
        q.push(make_pair(ret, node));
        mp[node->label] = ret;
        
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            
            for (UndirectedGraphNode* neighbor : front.second->neighbors) {
                if (mp.find(neighbor->label) == mp.end()) {
                    mp[neighbor->label] = new UndirectedGraphNode(neighbor->label);
                    q.push(make_pair(mp[neighbor->label], neighbor));
                }
                front.first->neighbors.push_back(mp[neighbor->label]);
            }
        }
        
        return ret;
    }
};