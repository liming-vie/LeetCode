class Solution {
public:
    vector<vector<string>> res;
    vector<vector<bool>> is;
    vector<bool> sum, diff, col;
    
    void solve(int vi, int n) {
        if(vi==n)   {
            vector<string> tmp;
            tmp.reserve(n);
            for(int i=0; i<n; ++i) {
                string t="";
                for(int j=0; j<n; ++j) {
                    if(is[i][j])    t+='Q';
                    else t+='.';
                }
                tmp.push_back(t);
            }
            res.push_back(tmp);
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

    vector<vector<string>> solveNQueens(int n) {
        sum.resize(n<<1, true);
        diff.resize(n<<1, true);
        col.resize(n, true);
        is.resize(n, vector<bool>(n, false));
        res.clear();
        solve(0, n);
        
        return res;
    }
};