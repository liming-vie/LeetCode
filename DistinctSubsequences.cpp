class Solution {
public:
    int numDistinct(string s, string t) {
        int sl=s.length(), tl=t.length();
        vector<int> dp(sl+1,0);
        dp[0]=1;
        for(int i=1; i<=tl; ++i) {
            for(int j=sl; j>=1; --j) {
                dp[j]=0;
                if(t[i-1]!=s[j-1])  continue;
                
                for(int k=j-1; k>=0; --k) {
                    dp[j]+=dp[k];
                }
            }
            dp[0]=0;
        }
        int res=0;
        for(int i=1; i<=sl; ++i)
            res+=dp[i];
        return res;
    }
};