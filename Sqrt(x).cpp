class Solution {
public:
    int mySqrt(int x) {
        int l=0, r=x;
        unsigned long long mid,tmp;
        while(l<=r) {
            mid=(l+r)>>1;
            tmp=mid*mid;
            if(tmp < x)
                l=mid+1;
            else if(tmp>x) 
                r=mid-1;
            else
                return mid;
        }
        return r;
    }
};