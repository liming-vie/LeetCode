class Solution {
public:
    bool isMatch(string s, string p) {
        int l1=s.length(), l2=p.length();
        vector<vector<bool>> dp(l1+1, vector<bool>(l2+1, false));
        dp[0][0]=true;
        for(int i=0; i<l2; ++i) {
            if(p[i]=='*')   dp[0][i+1]=true;
            else    break;
        }
        for(int i=1; i<=l1; ++i) {
            for(int j=1; j<=l2; ++j) {
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')  dp[i][j] = (dp[i-1][j]||dp[i][j-1]);
            }
        }
        return dp[l1][l2];
    }
};