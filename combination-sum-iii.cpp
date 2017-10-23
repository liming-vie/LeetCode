class Solution {
public:
    const int MAXN = 9;
    
    vector<vector<int>> res;
    vector<int> cur;
    
    void func(int vi, int target, int k) {
        if (target < 0 || MAXN-vi+1 < k || k<0) return;
        if (vi>MAXN || !k) {
            if (!target && !k)
                res.push_back(cur);
            return;
        }
        
        func(vi+1, target, k);
        
        cur.push_back(vi);
        func(vi+1, target-vi, k-1);
        cur.pop_back();
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        func(1, n, k);
        return res;
    }
};