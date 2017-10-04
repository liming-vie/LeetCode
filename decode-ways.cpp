class Solution {
public:
    int numDecodings(string s) {
        int l=s.length();
        if (l==0 || s[0] == '0')   return 0;
        
        vector<int> dp(l+1, 1);
        for(int i=1; i<l; ++i) {
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')) {
                dp[i+1] = dp[i-1];
                if (s[i] != '0') {
                    dp[i+1] += dp[i];
                }
            } else if (s[i] == '0') {
                return 0;
            }
            else {
                dp[i+1] = dp[i];
            }
        }
        return dp[l];
    }
};