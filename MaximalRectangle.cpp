class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=n==0?0:matrix[0].size();
        if(!n || !m)    return 0;
        // process length of '1' in each row
        vector<vector<int>> dp(n+1, vector<int>(m));
        for(int i=0; i<n; ++i) {
            dp[i][0]=matrix[i][0]-'0';
            for(int j=1; j<m; ++j){
                dp[i][j]= matrix[i][j]=='1'?dp[i][j-1]+1:0;
            }
        }
        for(int j=0; j<m; ++j)  dp[n][j]=0;
        // convert to similar problem as 84. Largest Rectangle in Histogram
        ++n;
        int res=0;
        for(int j=0; j<m; ++j) {
            stack<int> st;
            for(int i=0; i<n; ++i) {
                while(!st.empty() && dp[st.top()][j] > dp[i][j]) {
                    int t=st.top();
                    st.pop();
                    t=dp[t][j]*(st.empty()?i:i-st.top()-1);
                    res=t>res?t:res;
                }
                st.push(i);
            }
        }
        return res;
    }
};