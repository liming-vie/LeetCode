class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[105][105]={};
        for(int j=0; j<n && m>0; ++j)
            dp[m-1][j]=1;
        for(int i=m-2; i>=0; --i)
            for(int j=n-1; j>=0; --j){
                int a=dp[i+1][j];
                int b=(j==n-1)?0:dp[i][j+1];
                dp[i][j]=a+b;
            }
        return dp[0][0];
    }
};