class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        if(n<=0)    return vector<int>{-1,-1};
        if(n==1){
            if(A[0]==target)    return vector<int>{0,0};
            return vector<int>{-1,-1};
        }
        
        int l=0,r=n-1;
        int mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(A[mid]==target){
                l=mid;
                while(l>0 && A[l-1]==target)    --l;
                r=mid;
                while(r<n-1 && A[r+1]==target)  ++r;
                break;
            }else if(A[mid]>target) r=mid-1;
            else    l=mid+1;
        }
        if(l>r) l=r=-1;
        
        vector<int> res;
        res.push_back(l);
        res.push_back(r);
        return res;
    }
};