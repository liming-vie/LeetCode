class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len=s1.length();
        if(len!=s2.length())  return false;
        
        vector<vector<vector<bool>>> dp(len+1, vector<vector<bool>>(len+1, vector<bool>(len+1, false)));
        for(int i=0; i<len; ++i) {
            for(int j=0; j<len; ++j) {
                dp[i][j][0]=true;
                dp[i][j][1]=s1[i]==s2[j];
            }
        }
        
        for(int l=2; l<=len; ++l) {
            int u=len-l;
            for(int i=0; i<=u; ++i) {
                for(int j=0; j<=u; ++j) {
                    for(int k=0; k<=l; ++k) {
                        if ((dp[i][j + l - k][k] && dp[i + k][j][l - k])
              || (dp[i][j][k] && dp[i+k][j+k][l-k])) {
                            dp[i][j][l]=true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][len];
    }
};