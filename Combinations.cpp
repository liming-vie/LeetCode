class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    
    void func(int vi, int n, int k) {
        if(cur.size()==k)   {
            res.push_back(cur);
            return;
        }
        if(vi>n)   return;
        
        cur.push_back(vi);
        func(vi+1, n, k);
        cur.pop_back();
        
        func(vi+1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        func(1, n, k);
        return res;
    }
};