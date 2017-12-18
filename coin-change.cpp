class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        dp[0]=1;
        
        for (int n:coins) {
            for (int i=0; i<=amount-n; ++i) {
                if (!dp[i])  continue;
                else if (!dp[i+n] || dp[i]+1<dp[i+n])
                    dp[i+n] = dp[i]+1;
            }
        }
        
        return dp[amount]-1;
    }
};