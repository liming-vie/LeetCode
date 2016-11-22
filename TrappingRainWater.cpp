class Solution {
public:
    int max(int a,int b){
        return a<b?b:a;
    }

    int trap(int A[], int n) {
        if(n<=2)    return 0;
        
        int l=0,r=n-1,sech=0;
        int res=0;
        
        while(l<r){
            if(A[l]<A[r]){
                sech=max(sech,A[l]);
                res+=(sech-A[l]);
                ++l;
            }else{
                sech=max(sech,A[r]);
                res+=(sech-A[r]);
                --r;
            }
        }
        
        return res;
    }
};