class Solution {
public:
    int numDecodings(string s) {
        int len=s.length();
        if(!len)    return 0;
        
        vector<int> dp(len+1);
        dp[0]=1;
        for(int i=1; i<=len; ++i) {
            if(s[i]=='0')   dp[i]=dp[i-1];
            else {
                dp[i]=dp[i-1];
                if(i>1 && (s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<'7')))
                    dp[i]+=dp[i-2];
            }
        }
        return dp[len];
    }
};