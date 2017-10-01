class Solution {
public:
    vector<string> res;
    unordered_set<string> st;
    vector<string> removeInvalidParentheses(string s) {
        res.push_back("");
        st.insert("");
        dfs(s, "", 0, 0, 0);
        return res;
    }
    void dfs(const string& s, const string&cur, int left, int right, int vi) {
        if (right > left) return;
        
        if (vi==s.length()) {
            if (left==right && st.find(cur)==st.end()) {
                if (res[0].length() <= cur.length()) {
                    if (res[0].length() < cur.length()) {
                        st.clear();
                        res.clear();
                    }
                    res.push_back(cur);
                    st.insert(cur);
                }
            }
            return ;
        }
        switch (s[vi]) {
            case '(':
                dfs(s, cur+'(', left+1, right, vi+1);
                break;
            case ')':
                dfs(s, cur+')', left, right+1, vi+1);
                break;
            default:
                dfs(s, cur+s[vi], left, right, vi+1);
                return;
        }
        dfs(s, cur, left, right, vi+1);
    }
};