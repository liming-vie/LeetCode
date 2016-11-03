class Solution {
public:
    int find(int a[],int l,int r,int target){
        if(l>r) return -1;
        
        int mid;
        if(a[l]<=a[r]){
            while(l<=r){
                mid=(l+r)>>1;
                if(target==a[mid])  return mid;
                else if(target<a[mid])  r=mid-1;
                else l=mid+1;
            }
            return -1;
        }else{
            mid=(l+r)>>1;
            int tmp=find(a,l,mid,target);
            if(tmp!=-1)    return tmp;
            return find(a,mid+1,r,target);
        }
    }

    int search(int A[], int n, int target) {
        return find(A,0,n-1,target);
    }
};