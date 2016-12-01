class Solution {
public:
    string getPermutation(int n, int k) {
        int fac[11]={1,1};
        for(int i=1; i<=n; ++i) fac[i] = fac[i-1]*i;
        
        --k;
        string res="";
        bool use[11]={};
        for(int i=n-1; i>=0; --i) {
            int t=k/fac[i];
            // find t-th number
            int cur=0;
            for(int j=1; j<=n; ++j) {
                if(use[j])  continue;
                if(cur==t) {
                    cur=j;
                    break;
                }
                ++cur;
            }
            use[cur]=true;
            res += (char)(cur+'0');
            k%=fac[i];
        }
        return res;
    }
};