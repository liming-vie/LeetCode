class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=1)    return n;
        int t=A[0];
        int len=1;
        for(int i=1;i<n; ++i){
            if(A[i]==t) continue;
            else{
                t=A[i];
                A[len++]=t;
            }
        }
        return len;
    }
};