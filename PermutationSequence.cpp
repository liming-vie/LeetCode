class Solution {
public:
    int t[11]={1,1};
    bool is[11]={};
    
    int findk(int k, int n){
        int c=0;
        for(int i=1; i<=n; ++i){
            if(is[i])   continue;
            if((++c) == k){
                is[i]=true;
                return i;
            }    
        }
    }
    
    string getPermutation(int n, int k) {
        for(int i=2; i<=n; ++i){
            t[i]=t[i-1]*i;
        }
        
        string res="";
        
        for(int i=0; i<n; ++i){
            res+=(findk((k-1)/t[n-i-1] + 1, n)+'0');
            k%=t[n-i-1];
            if(k==0)    k=t[n-i-1];
        }
        return res;
    }
};