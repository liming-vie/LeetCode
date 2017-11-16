class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> count(strs.size()); // zero, one
        for (int i=0; i<strs.size(); ++i) {
          int one=0;
          for (char c : strs[i]) {
            one += c-'0';
          }
          count[i] = make_pair(strs[i].length()-one, one);
        }

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i=0; i<strs.size(); ++i) {
          int z=count[i].first, o=count[i].second;
          for (int zero = m-z; zero >= 0; --zero) {
            for (int one = n-o; one >= 0; --one) {
              dp[zero+z][one+o] = max(dp[zero+z][one+o], dp[zero][one]+1);
            }
          }
        }
        return dp[m][n];
    }
};

