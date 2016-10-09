class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        for(int i=2; i<=n; ++i) {
            for(int j=i-1; j>0; --j){
                dp[j][i] = 0x7FFFFFFF;
                for(int k=j; k<i; ++k) {
                    dp[j][i] = min(dp[j][i], k + max(dp[j][k-1], dp[k+1][i]));
                }
            }
        }
        return dp[1][n];
    }
};