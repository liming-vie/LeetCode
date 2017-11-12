class Solution {
public:
    int findIntegers(int num) {
        int hi;
        for (hi=31; hi>=0; --hi) {
            if (num&(1<<hi)) {
                break;
            }
        }
        
        int zero[32]={1};
        int one[32]={1};
        for (int i=1; i<=hi; ++i) {
            zero[i] = one[i-1]+zero[i-1];
            one[i] = zero[i-1];
        }
        
        int res=one[hi]+zero[hi];
        int pre=1;
        for (int i=hi-1; i>=0; --i) {
            if (num&(1<<i)) {
                if (pre)    return res;
                pre = 1;
            } else {
                if (!pre)   res -= one[i];
                pre=0;
            }
        }
        return res;
    }
};