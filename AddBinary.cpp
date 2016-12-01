class Solution {
public:
    string addBinary(string a, string b) {
        int len1=a.length(),len2=b.length();
        if(len1==0)    return b;
        if(len2==0)    return a;
        
        string res="";
        int i,j,sum,k=0;
        for(i=len1-1,j=len2-1; ; --i,--j){
            if(j>=0 && i>=0){
                sum=a[i]+b[j]-('0'+'0')+k;
            }else if(j>=0){
                sum=b[j]-'0'+k;
            }else if(i>=0){
                sum=a[i]-'0'+k;
            }else break;
            
            k=(sum>>1);
            res=(char)((sum&1)+'0')+res;
        }
        while(k>0){
            res=(char)((k&1)+'0')+res;
            k >>= 1;
        }
        return res;
    }
};