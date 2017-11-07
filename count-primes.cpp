class Solution {
public:
    int countPrimes(int n) {
        bool *has = new bool[n+1];
        memset(has, 0, n+1);
        int res=0;
        for (int i=2; i<n; ++i) {
            if (has[i]) continue;
            ++res;
            for (int j=n/i; j>1; --j) {
                has[i*j]=true;
            }
        }
            
        return res;
    }
};