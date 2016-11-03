class Solution {
public:
    int divide(int dividend, int divisor) {
        int max=~(1<<31),min=1<<31;
        
        if(divisor==0)  return max;
        
        long long int d=dividend,s=divisor,tmp,k=0,res=0;
        
        bool neg1=(d<0),neg2=(s<0);
        if(neg1)    d=0-d;
        if(neg2)    s=0-s;
        
        if(d<s) return 0;
    
        if(s==1)    res=d;
        else{
            tmp=s;
            while((tmp<<=1)<=d)   ++k;
            tmp>>=1;
            
            while(d>=s){
                while(d<tmp){
                    --k;
                    tmp>>=1;
                }
                res+=(1<<k);
                d-=tmp;
            }
        }
        
        if(neg1!=neg2)  res=0-res;
        if(res<min||res>max)    return max;
        return res;
    }
};