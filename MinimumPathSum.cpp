class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(!m)  return 0;
        int n=grid[0].size();
        if(!n)  return 0;
        
        int dp[200][200]={};
        dp[m-1][n-1]=grid[m-1][n-1];
        for(int j=n-2; j>=0; --j)
            dp[m-1][j]=dp[m-1][j+1]+grid[m-1][j];
            
        for(int i=m-2; i>=0; --i)
            for(int j=n-1; j>=0; --j){
                int a=dp[i+1][j];
                if(j==n-1)
                    dp[i][j]=a+grid[i][j];
                else{
                    int b=dp[i][j+1];
                    dp[i][j]=grid[i][j]+(a<b?a:b);
                }
            }
        return dp[0][0];
    }
};