class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(); if (!m)  return 0;
        int n=obstacleGrid[0].size(); if (!n)   return 0;
        if (obstacleGrid[0][0]) return 0;
        
        vector<int> dp(n+1, 0);
        dp[1]=1;
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (obstacleGrid[i-1][j-1])
                    dp[j] = 0;
                else dp[j] += dp[j-1];
            }
        }
        return dp[n];
    }
};