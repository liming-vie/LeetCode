#define MAXN 2005
#define ZERO 1001
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S>1000 || S<-1000)  return 0;
        
        int dp[2][MAXN];
        memset(dp, 0, sizeof(int)*MAXN);
        int cur=0;
        dp[cur][ZERO] = 1;
        
        for (int i=1; i<=nums.size(); ++i) {
            cur = 1-cur;
            memset(dp[cur], 0, sizeof(int)*MAXN);
            for (int j=0; j<MAXN; ++j) {
                if (dp[1-cur][j]) {
                    dp[cur][j+nums[i-1]] += dp[1-cur][j];
                    dp[cur][j-nums[i-1]] += dp[1-cur][j];
                }
            }
        }
        
        return dp[cur][S+ZERO];
    }
};