class Solution {
public:
    int mySqrt(int x) {
        int l=0, r=x, mid;
        long long tmp;
        while (l<=r) {
            mid = l+((r-l)>>1);
            tmp=(long long)mid*mid;
            if (tmp == x)   return mid;
            if (tmp < x)    l=mid+1;
            else    r=mid-1;
        }
        return r;
    }
};