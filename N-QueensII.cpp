class Solution {
public:
    vector<vector<bool>> is;
    vector<bool> sum, diff, col;
    int res;
    
    void solve(int vi, int n) {
        if(vi==n)   {
            ++res;
            return;
        }
        
        for(int i=0; i<n; ++i) {
            if(col[i] && sum[vi+i] && diff[vi-i+n]) {
                col[i] = false;
                sum[vi+i]=false;
                diff[vi-i+n]=false;
                is[vi][i]=true;
                solve(vi+1, n);
                is[vi][i]=false;
                col[i] = true;
                sum[vi+i]=true;
                diff[vi-i+n]=true;
            }
        }
    }
    
    int totalNQueens(int n) {
        sum.resize(n<<1, true);
        diff.resize(n<<1, true);
        col.resize(n, true);
        is.resize(n, vector<bool>(n, false));
        res=0;
        solve(0, n);
        return res;
    }
};