class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n==1)   return vector<int>{0};
        
        vector<unordered_set<int>> adj(n);
        for (const auto& e:edges) {
            adj[e.first].insert(e.second);
            adj[e.second].insert(e.first);
        }
        
        vector<int> st[2];
        int cur=0;
        for (int i=0; i<n; ++i) {
            if (adj[i].size()==1) {
                st[cur].push_back(i);
            }
        }
        
        vector<int> res;
        while (true) {
            st[1-cur].clear();
            
            for (int node:st[cur]) {
                for (int next:adj[node]) {
                    adj[next].erase(node);
                    if (adj[next].size()==1) {
                        st[1-cur].push_back(next);
                    }
                }
                adj[node].clear();
            }
            
            if (st[1-cur].empty()) {
                return st[cur];
            }
            cur=1-cur;
        }
        
        return st[cur];
    }
};