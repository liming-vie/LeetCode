class Solution {
public:
    int numTrees(int n) {
        if(!n)  return 0;
        
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for(int i=0; i<=n; ++i) dp[i][i]=1;
        for(int l=2; l<=n; ++l) {
            int ui=n-l+1;
            for(int i=1; i<=ui; ++i) {
                int j=i+l-1;
                dp[i][j]=dp[i][j-1]+dp[i+1][j];
                for(int k=i+1; k<j; ++k) {
                    dp[i][j] += dp[i][k-1]*dp[k+1][j];
                }
            }
        }
        return dp[1][n];
    }
};