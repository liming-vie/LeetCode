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
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(!node)	return NULL;
        if(mp.find(node)!=mp.end())	return mp[node];

        auto move=new UndirectedGraphNode(node->label);
        mp[node]=move;
        move->neighbors.reserve(node->neighbors.size());
        for(auto neighbor:node->neighbors) {
        	move->neighbors.push_back(cloneGraph(neighbor));
        }
        return move;
    }
};