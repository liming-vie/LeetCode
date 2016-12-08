class Solution {
public:
    vector<vector<int>> res;
    vector<int> tres;
    
    void func(int vi, int n, int k){
        if(!k){
            res.push_back(tres);
            return;
        }
        
        while(n-vi+1>=k){
            tres.push_back(vi);
            func(++vi,n,k-1);
            tres.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        if(k>n) return res;
        if(k==n){
            for(int i=1; i<=n; ++i)
                tres.push_back(i);
            res.push_back(tres);
            return res;
        }
        func(1,n,k);
        return res;
    }
};