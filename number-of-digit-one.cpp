class Solution {
public:
    int countDigitOne(int n) {
        int res=0;
        for (long long m=1; m<=n; m*=10) {
            long long a=n/m;
            res += (a+8)/10*m + ((a%10)==1?((n%m)+1):0);
        }
        return res;
    }
};