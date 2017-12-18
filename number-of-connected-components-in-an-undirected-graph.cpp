class Solution {
public:
    int find(vector<int>& parent, int vi) {
        if (parent[vi]==vi) return vi;
        
        parent[vi] = find(parent, parent[vi]);
        return parent[vi];
    }
    
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> parent(n);
        for (int i=0; i<n; ++i) parent[i]=i;
        
        int res=n;
        for (const auto &kv:edges) {
            int p1=find(parent, kv.first);
            int p2=find(parent, kv.second);
            if (p1==p2) continue;
            parent[p1]=p2;
            --res;
        }
        
        return res;
    }
};