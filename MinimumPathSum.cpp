class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=n==0?0:grid[0].size();
        if(!n || !m)    return 0;
        
        vector<int> dp(m+1, ~(1<<31));
        dp[1]=0;
        for(int i=0; i<n; ++i) {
            for(int j=1; j<=m; ++j) {
                dp[j] = min(dp[j],dp[j-1])+grid[i][j-1];
            }
        }
        return dp[m];
    }
};