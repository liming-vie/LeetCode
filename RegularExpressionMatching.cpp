class Solution {
public:
    inline bool isMatch(string s, string p) {
        int l1=s.length(),l2=p.length();
        vector<vector<bool>>dp(l1+1,vector<bool>(l2+1,false));
        dp[0][0]=true;
        for(int i=1; i<=l1; ++i){
            dp[i][0] = false;
        }
        for(int j=1; j<=l2; ++j) {
            dp[0][j] = p[j-1]=='*' ? dp[0][j-2] : false;
        }
        for(int i=1; i<=l1; ++i) {
            for(int j=1; j<=l2; ++j) {
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i][j-2] || (dp[i-1][j] && (p[j-2]=='.'||p[j-2]==s[i-1]));
                }
                else {
                    dp[i][j] = dp[i-1][j-1] && (p[j-1]=='.' || p[j-1] == s[i-1]);
                }
            }
        }
        return dp[l1][l2];
    }
};