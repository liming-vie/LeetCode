class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if (!n) return 0;
        
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxl=1;
        for (int i=1; i<n; ++i) {
            for (int j=i-1; j>=0; --j) {
                if (nums[j]<nums[i]) {
                    if (dp[i] == dp[j]+1) {
                        count[i] += count[j];
                    } else if (dp[i] < dp[j]+1) {
                        count[i] = count[j];
                        dp[i] = dp[j]+1;
                    }
                }
            }
            maxl = max(maxl, dp[i]);
        }
        
        int res=0;
        for (int i=0; i<n; ++i) {
            if (dp[i]==maxl)
                res += count[i];
        }
        
        return res;
    }
};