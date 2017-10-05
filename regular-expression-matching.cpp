class Solution {
public:
    bool isMatch(string s, string p) {
        int sl=s.length(), pl=p.length();
        vector<vector<bool>> match(sl+1, vector<bool>(pl+1, false));
        match[0][0] = true;
        for (int i=1; i<=pl; ++i) {
            match[0][i] = (p[i-1] == '*' && match[0][i-2]); // match begin
        }
        
        for (int i=1; i<=sl; ++i) {
            for (int j=1; j<=pl; ++j) {
                switch (p[j-1]) {
                    case '*':
                        match[i][j] = match[i][j-2] // zero
                            || match[i][j-1] // one
                            || (match[i-1][j] && (p[j-2] == '.' || p[j-2] == s[i-1])); // multiple
                        break;
                    case '.':
                        match[i][j] = match[i-1][j-1];
                        break;
                    default:
                        match[i][j] = (p[j-1] == s[i-1]) && match[i-1][j-1];
                }
            }
        }
        
        return match[sl][pl];
    }
};