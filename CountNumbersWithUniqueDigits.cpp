class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)    return 1;
        int cur=10;
        for(int i=1; i<n; ++i) {
            if(i>9) break;
            int k=9;
            int s=9;
            for(int j=1; j<=i; ++j) {
                s*=(k--);
            }
            cur += s;
        }
        return cur;
    }
};