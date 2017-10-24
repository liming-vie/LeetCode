class Solution {
public:
    bool isMatch(string s, string p) {
        int ls=s.length(), lp=p.length();
        vector<vector<bool>> dp(ls+1, vector<bool>(lp+1, false));
        
        dp[0][0]=true;
        for(int i=0; i<lp && p[i]=='*'; ++i)
            dp[0][i+1]=true;
        
        for (int i=0; i<ls; ++i) {
            for (int j=0; j<lp; ++j) {
                if (s[i]==p[j] || p[j]=='?') dp[i+1][j+1]=dp[i][j];
                else if (p[j]=='*') dp[i+1][j+1] = dp[i+1][j] || dp[i][j+1];
            }
        }
        
        return dp[ls][lp];
    }
};