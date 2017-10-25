class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)    return 1.0;
        double tmp=myPow(x, abs(n/2));
        tmp *= tmp;
        if(n&1) tmp *= x;
        if(n<0) tmp=1.0/tmp;
        return tmp;
    }
};