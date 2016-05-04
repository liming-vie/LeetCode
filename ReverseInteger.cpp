class Solution {
public:
    int reverse(int x) {
        bool neg= (x<0);
        long long int tmp=x;
        if(neg) tmp = 0-tmp;
        char res[100];
        int n=0;
        long long int k=1;
        while(tmp>0){
            res[n++]=tmp%10;
            tmp/=10;
            k*=10;
        }
        
        long long int resl=0;
        for(int i=0; i<n; ++i){
             k/=10;   
             resl+=res[i]*k;
        }
        if(neg){
            resl=0-resl;  
        } 
        if(resl < (1<<31) || resl > (~(1<<31))) return 0;
        return resl;
    }
};