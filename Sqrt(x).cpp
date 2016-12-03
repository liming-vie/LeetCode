class Solution {
public:
    int mySqrt(int x) {
        if(x<=1ull) return x;
        unsigned long long l=0,r=(x+1)/2;
        unsigned long long mid;
        unsigned long long res;
        while(l<r){
            mid=(l+r)>>1;
            res=mid*mid;
            if(res==x)  return mid;
            if(res<x)   l=mid+1;
            else    r=mid-1;
        }
        res=r*r;
        if(res>x)   return r-1;
        return r;
    }
};