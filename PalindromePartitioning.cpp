class Solution {
public:
    int len;
    vector<vector<string>> res;
    vector<string> cur;
    
    void generate(string& s, vector<vector<bool>>&dp, int vi) {
        if(vi==len) {
            res.push_back(cur);
            return;
        }
        for(int i=vi; i<len; ++i) {
            if(dp[vi][i]) {
                cur.push_back(s.substr(vi, i-vi+1));
                generate(s, dp, i+1);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        len=s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for(int i=0; i<len; ++i)    dp[i][i]=true;
        for(int i=1; i<len; ++i)    dp[i-1][i]=(s[i-1]==s[i]);
        for(int l=3; l<=len; ++l) {
            for(int i=0; i<=len-l; ++i) {
                int j=i+l-1;
                if(s[i]==s[j] && dp[i+1][j-1])
                    dp[i][j]=true;
            }
        }
        generate(s, dp, 0);
        return res;
    }
};