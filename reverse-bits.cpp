class Solution {
public:

#define SET(num, val, vi)   \
    if (val) {              \
        num |= (1<<vi);     \
    } else {                \
        num ^= (1<<vi);     \
    }
    
    uint32_t reverseBits(uint32_t n) {
        int i=0, j=31;
        while (i<j) {
            int a=((1<<i)&n);
            int b=((1<<j)&n);
            if ((a!=0)!=(b!=0)) {
                SET(n, a, j)
                SET(n, b, i)
            }
            ++i;
            --j;
        }
        return n;
    }
};