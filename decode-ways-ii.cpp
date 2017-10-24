class Solution {
public:
    int MOD=1000000007;
    
    int numDecodings(string s) {
        int len=s.length();
        vector<long long> dp(len+1, 0);
        dp[0] = 1;
        for (int i=0; i<len; ++i) {
            if (s[i] != '0') {
                dp[i+1] = dp[i] * (s[i]=='*'?9:1);
            } else if(!i || (s[i-1]!='*' && (s[i-1]=='0' || s[i]>'2')))
                return 0;

            if (!i || s[i-1]=='0' || s[i-1]>'2') {
                dp[i+1] %= MOD;
                continue;
            }

            if (s[i] == '*') {
                if (s[i-1]=='*')   dp[i+1]+=dp[i-1]*15;
                else if (s[i-1]=='1')   dp[i+1]+=dp[i-1]*9;
                else if (s[i-1]=='2')   dp[i+1]+=dp[i-1]*6;
            } else if (s[i]<'7') {
                dp[i+1]+=dp[i-1]*(s[i-1]=='*'?2:1);
            }
            else if (s[i-1]=='*' || s[i-1]=='1') dp[i+1]+=dp[i-1];
            dp[i+1] %= MOD;
        }
        return dp[len];
    }
};