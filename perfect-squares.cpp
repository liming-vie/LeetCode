class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        for (int i=1; i<=sqrt(n); ++i)
            nums.push_back(i*i);
        
        vector<int> dp(n+1, n+1);
        dp[0] = 0;
        
        for (int num:nums) {
            for (int i=num; i<=n; ++i) {
                dp[i] = min(dp[i], dp[i-num]+1);
            }
        }
        
        return dp[n];
    }
};