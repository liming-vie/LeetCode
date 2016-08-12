#define min(a,b) a<b?a:b

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max=~(1<<31);
        int* dp = new int[amount+1];
        fill_n(dp+1, amount, max);
        dp[0] = 0;
        int n=coins.size();
        for(int i=0; i<n; ++i) {
            for(int j=coins[i]; j<=amount; ++j) {
                int a=dp[j], b=dp[j-coins[i]];
                dp[j] = b == max ? a : min(a, b + 1);
            }
        }
        
        return dp[amount] == max? -1 : dp[amount];
    }
};