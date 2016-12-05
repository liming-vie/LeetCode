class Solution {
public:
    int dp[1000][1000];
    int minDistance(string word1, string word2) {
        int l1=word1.length();
        int l2=word2.length();
        for(int i=0; i<=l1; ++i)
            dp[i][0]=i;
        for(int j=0; j<=l2; ++j)
            dp[0][j]=j;
        for(int i=1; i<=l1; ++i)
            for(int j=1; j<=l2; ++j){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                    continue; 
                }  
                int a=dp[i-1][j-1]<dp[i][j-1]?dp[i-1][j-1]:dp[i][j-1];
                dp[i][j]=(a<dp[i-1][j]?a:dp[i-1][j])+1;
            }
        return dp[l1][l2];
    }
};