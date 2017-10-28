class Solution {
public:
    int numWays(int n, int k) {
        if (n==0 || k==0)   return 0;
        if (n==1)   return k;
        
        int diff=k, same=0;
        for (int i=1; i<n; ++i) {
            int tmp = (same+diff) * (k-1);
            same = diff;
            diff = tmp;
        }
        return diff + same;
    }
};