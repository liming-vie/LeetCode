class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size(); if (!n)  return 0;
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for (int l=1; l<=n; ++l) {
            for (int i=1; i<=n; ++i) {
                int j=i+l-1;
                if (j>n)   break;
                dp[i][j] = max(nums[i-1]-dp[i+1][j], nums[j-1]-dp[i][j-1]);
            }
        }
        return dp[1][n]>=0;
    }
};