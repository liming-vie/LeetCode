#define MAX_INT 2147483647
#define MIN_INT -2147483648

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ldividend = dividend < 0 ? -((long long)dividend) : dividend;
        long long ldivisor = divisor < 0 ? -((long long)divisor) : divisor;
        
        int k=0;
        while (ldividend >= (ldivisor << k)) {
            ++k;
        }
        --k;
        long long res = 0;
        while (ldividend >= ldivisor) {
            res += (1LL<<k);
            ldividend -= (ldivisor << k);
            while (ldividend < (ldivisor<<k)) {
            --k;
            }
        }
        
        res = ((dividend<0)^(divisor<0))?-res:res;
        return (res > MAX_INT || res < MIN_INT) ? MAX_INT : res;
    }
};