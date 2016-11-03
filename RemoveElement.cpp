class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int v[10000],len1=0;
        int s[10000],len2=0;
        for(int i=0; i<n; ++i){
            if(A[i]==elem)
                v[len1++]=i;
            else
                s[len2++]=i;
        }
        if(len1==0 || (len1>0 && v[0] == len2))  return len2;
        
        int t=len2-1;
        for(int i=0; i<len1 && t>=0; ++i,--t){
            A[v[i]] = A[s[t]];
        }
        return len2;
    }
};