class Solution {
public:
    vector<vector<int>> dp;
    
    int d[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    
    int func(const vector<vector<int>>& matrix, int vi, int vj) {
        if (dp[vi][vj]) return dp[vi][vj];
        
        int l=0;
        for (int i=0; i<4; ++i) {
            int x=vi+d[i][0], y=vj+d[i][1];
            if (x<0 || x==matrix.size() || y<0 || y==matrix[0].size() || matrix[x][y]<=matrix[vi][vj])
                continue;
            l = max(func(matrix, x, y), l);
        }
        dp[vi][vj] = l+1;
        return dp[vi][vj];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();    if (!n) return 0;
        int m=matrix[0].size(); if (!m) return 0;
        
        dp = vector<vector<int>>(n, vector<int>(m, 0));
        
        int res=0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                res = max(res, func(matrix, i, j));
            }
        }
        
        return res;
    }
};