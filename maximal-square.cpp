class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(); if (!n)    return 0;
        int m=matrix[0].size();
        
        vector<int> dp(m+1, 0); // the longest length of side for square end at i,j
        int res=0, tmp;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (matrix[i][j]=='1') {
                    tmp=min(dp[j], dp[j+1]);
                    dp[j+1]=tmp+(matrix[i-tmp][j-tmp]=='1');
                    res = max(res, dp[j+1]);
                } else dp[j+1]=0;
            }
        }
        
        return res*res;
    }
};