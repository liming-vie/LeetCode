#define MAX_INT ~(1<<31)
#define MIN_INT 1<<31
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long end = dividend, sor = divisor;
        end = end < 0 ? -end : end;
        sor = sor < 0 ? -sor : sor;
        long long int res = 0;
        long long int k = 0, tmp = sor;
        while (tmp <= end) {
            tmp <<= 1;
            ++k;
        }
        while (end >= sor) {
            while (tmp > end) {
                tmp >>= 1;
                --k;
            }
            res += 1LL << k;
            end -= tmp;
        }
        res = ((dividend<0) ^ (divisor<0)) ? -res : res;
        return (res<MIN_INT || res>MAX_INT) ? MAX_INT : res;
    }
};