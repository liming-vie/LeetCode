class Solution {
public:
    int numSquares(int n) {
        if (n==0)   return 0;
        
        vector<int> nums;
        for (int i=1; i<=sqrt(n); ++i)
            nums.push_back(i*i);
        
        static vector<int> dp{0};
        while (dp.size()<=n) {
            int i=dp.size(), dp_i=n+1;
            for (int j=0; nums[j]<=i && j<nums.size(); ++j) {
                dp_i = min(dp_i, dp[i-nums[j]]+1);
            }
            dp.push_back(dp_i);
        }
        
        return dp[n];
    }
};