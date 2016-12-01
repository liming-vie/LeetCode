class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        if(m==0)    return 0;
        int n=obstacleGrid[0].size();
        int dp[105][105]={};
        for(int j=n-1; j>=0 && !obstacleGrid[m-1][j]; --j)
            dp[m-1][j]=1;
        for(int i=m-2; i>=0; --i)
            for(int j=n-1; j>=0; --j){
                if(obstacleGrid[i][j])  continue;
                int a=dp[i+1][j];
                int b=(j==n-1?0:dp[i][j+1]);
                dp[i][j]=a+b;
            }
        return dp[0][0];
    }
};