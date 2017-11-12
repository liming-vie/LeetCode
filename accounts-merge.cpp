class Solution {
public:
    vector<int> parent;
    
    int find(int vi) {
        if (parent[vi]==vi)   return vi;
        
        parent[vi] = find(parent[vi]);
        return parent[vi];
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        
        parent = vector<int>(n);
        for (int i=0; i<n; ++i) parent[i] = i;
        
        map<string, int> emails;
        for (int i=0; i<accounts.size(); ++i) {
            for (int j=1; j<accounts[i].size(); ++j) {
                if (emails.find(accounts[i][j]) != emails.end()) {
                    parent[find(i)] = find(emails[accounts[i][j]]);
                }
                emails[accounts[i][j]] = find(i);
            }
        }
        
        unordered_map<int, vector<string>> res_map;
        for (const auto& kv : emails) {
            int p=find(kv.second);
            if (res_map[p].empty()) res_map[p].push_back(accounts[p][0]);
            res_map[p].push_back(kv.first);
        }
        
        vector<vector<string>> res;
        for (const auto & kv : res_map) {
            res.push_back(kv.second);
        }
        return res;
    }
};