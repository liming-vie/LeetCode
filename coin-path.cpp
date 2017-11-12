class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n=A.size();
        vector<int> res;
        if (n<1 || A[0]==-1 || A[n-1]==-1)    return res;
        
        vector<int> dp(n, -1);
        vector<int> idx(n);
        dp[n-1]=A[n-1];
        idx[n-1]=-1;
        
        for (int i=n-2; i>=0; --i) {
            if (A[i]==-1) continue;
            
            for (int j=i+1; j<=min(i+B, n-1); ++j) {
                if (dp[j]!=-1 && (dp[i]==-1 || dp[i]>dp[j]+A[j])) {
                    dp[i]=dp[j]+A[j];
                    idx[i]=j;
                }
            }
        }
        
        if (dp[0]==-1)  return res;
        int pi=0;
        while (pi!=-1) {
            res.push_back(pi+1);
            pi=idx[pi];
        }
        return res;
    }
};