class Solution {
public:
    std::vector<int> dp;
    
    int helper(int n) {
        if (n<=3)   return n;
        if (dp[n])  return dp[n];
        int res=n;
        for (int i=1; i<=(n>>1); ++i) {
            res = max(res, i*helper(n-i));
        }
        return dp[n]=res;
    }
    
    int integerBreak(int n) {
        dp = vector<int>(n+1, 0);
        int res=0;
        for (int i=1; i<=(n>>1); ++i) {
            res=max(res, i*helper(n-i));
        }
        return res;
    }
};