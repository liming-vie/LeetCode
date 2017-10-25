class Solution {
public:
    double myPow(double x, int n) {
        if (n==0)   return 1.;

        long t = n < 0 ? -(long)n : n;
        
        double ans = 1;
        while (t) {
            if (t&1)    ans *= x;
            x*=x;
            t>>=1;
        }
        return n<0 ? 1./ans : ans;
    }
};