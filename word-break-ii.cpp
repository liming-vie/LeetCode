class Solution {
public:
    vector<vector<int>> dp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (const string& word : wordDict)
            st.insert(word);
        
        int len=s.length();
        dp = vector<vector<int>>(len, vector<int>(len, 0));
        for (int i=0; i<len; ++i) {
            for (int j=i; j>=0; --j) {
                if (st.find(s.substr(j,i-j+1)) != st.end()) {
                    dp[j][i] = 1;
                } else {
                    for (int k=j; k<i; ++k) {
                        if (dp[j][k] && dp[k+1][i]) {
                            dp[j][i] = 2;
                            break;
                        }
                    }
                }
            }
        }
        
        if (!dp[0][len-1])  return res;
        
        search(s, "", 0);
        return res;
    }
    
    vector<string> res;
    void search(const string& str, const string& cur, int vi) {
        if (vi == str.length()) {
            res.push_back(cur);
            return;
        }
        
        string c = cur.length() ? " " : "";
        for (int i=vi; i<str.length(); ++i) {
            if (dp[vi][i] == 1) {
                search(str, cur+c+str.substr(vi, i-vi+1), i+1);
            }
        }
    }
    
};