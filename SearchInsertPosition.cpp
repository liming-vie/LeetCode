class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n<=0)    return 0;
        
        int l=0,r=n-1,mid;
        while(l<r){
            mid=(l+r)>>1;
            if(A[mid]<target)    l=mid+1;
            else if(A[mid]>target)  r=mid-1;
            else return mid;
        }
        
        if(A[l]>=target)    return l;
        return l+1;
        
    }
};