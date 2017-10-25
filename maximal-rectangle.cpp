class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (!matrix.size()) return 0;
        int n=matrix.size(), m=matrix[0].size();
        
        int res=0;
        vector<int> dp(m+1, 0);
        for (int i=0; i<n; ++i) {
            stack<pair<int, int>> st; // i, h
            st.push(make_pair(-1,0));
            for (int j=0; j<=m; ++j) {
                if (j<m && matrix[i][j] == '1')    ++dp[j];
                else dp[j]=0;
                
                int last = j;
                while (st.top().second > dp[j]) {
                    res = max(res, st.top().second * (j-st.top().first));
                    last = st.top().first;
                    st.pop();
                }
                
                st.push(make_pair(last, dp[j]));
            }
        }
        return res;
    }
};