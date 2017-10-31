class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(), m=n==0?0:obstacleGrid[0].size();
        if(!n || !m || obstacleGrid[0][0]==1)   
            return 0;
            
        vector<int> dp(m+1,0);
        dp[1]=1;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                if(obstacleGrid[i-1][j-1]) 
                    dp[j]=0;
                else {
                    dp[j]+=dp[j-1];
                }
            }
        }
        return dp[m];
    }
};