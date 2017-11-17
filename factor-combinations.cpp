class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    void dps(int n, int vi) {
        if (n == 1) {
            if (cur.size()>1) {
                res.push_back(cur);
            }
            return ;
        }
        
        for (int i=vi; i<=n; ++i) {
            if (n%i==0) {
                cur.push_back(i);
                dps(n/i, i);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        if (n<2) return res;
        
        dps(n, 2);
        return res;
    }
};