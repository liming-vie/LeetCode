class Solution {
public:
    bool isMatch(string s, string p) {
        int slen=s.length();
        int plen=p.length();
        
        int count=0;
        for(int i=0; i<plen; ++i)
            if(p[i]!='*')   ++count;
        if(count>slen)  return false;
        
        bool **dp=new bool*[slen+1];
        for(int i=0; i<=slen; ++i){
            dp[i]=new bool[plen+1];
            memset(dp[i],0,plen+1);
        }
        
        dp[0][0]=true;
        for(int j=0; j<plen; ++j){
            if(p[j]=='*') dp[0][j+1]=true;
            else break;
        }
        
        for(int i=1; i<=slen; ++i)
            for(int j=1; j<=plen; ++j){
                if(s[i-1]==p[j-1] || p[j-1]=='?')  dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j]=(dp[i-1][j]||dp[i][j-1]);
                else    dp[i][j]=false;
            }
    
        return dp[slen][plen];
    }
};