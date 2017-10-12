class Solution {
public:
    vector<int> parent;
    
    int find(int vi) {
        if (parent[vi] == vi)   return vi;
        parent[vi] = find(parent[vi]);
        return parent[vi];
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        parent = vector<int>(n);
        for (int i=0; i<n; ++i) parent[i] = i;
        
        for (const auto& p : edges) {
            int p1=find(p.first);
            int p2=find(p.second);
            if (p1==p2) return false;
            
            parent[p1] = parent[p2];
        }
        
        return edges.size() == n-1;
    }
};