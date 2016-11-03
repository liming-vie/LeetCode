#define max(a,b)    a<b?b:a
class Solution {
public:
    int longestValidParentheses(string s) {
        int len=s.length();
        if(len<2)   return 0;
        
        // max valid str length ends with i
        vector<int> dp(len, 0);
        dp[1]=(s[0]=='(' && s[1]==')')?2:0;
        
        int res=dp[1];
        for(int i=2; i<len; ++i) {
            if(s[i]=='(')  continue;
            // two condition
            if(s[i-1]=='(') dp[i]=dp[i-2]+2;
            if(i>dp[i-1] && s[i-dp[i-1]-1]=='(')    dp[i]=max(dp[i], dp[i-1]+2);
            // concate with previews valid string
            if(i>dp[i])    dp[i]+=dp[i-dp[i]];
            
            res=max(res, dp[i]);
        }
        
        return res;
    }
};