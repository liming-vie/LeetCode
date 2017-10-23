class Solution {
public:
    vector<int> cur;
    vector<vector<int>> res;
    
    void func(const vector<int>& candidates, int vi, int target) {
        if (vi==candidates.size()) {
            if (target==0)  res.push_back(cur);
            return ;
        }
        
        int maxn=target/candidates[vi];
        for (int i=0; i<maxn; ++i) {
            cur.push_back(candidates[vi]);
            target -= candidates[vi];
            func(candidates, vi+1, target);
        }
        
        for (int i=0; i<maxn; ++i)
            cur.pop_back();
        target += candidates[vi]*maxn;
        
        func(candidates, vi+1, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        func(candidates, 0, target);
        return res;
    }
};