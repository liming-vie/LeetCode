class Solution {
public:
    string multiply(string num1, string num2) {
        int len1=num1.length(),len2=num2.length();
        
        if(len1==0||len2==0)    return "";
        
        for(int i=0; i<len1; ++i)   num1[i]-='0';
        for(int j=0; j<len2; ++j)   num2[j]-='0';
        
        int tmp[10000]={0};
        for(int i=0; i<len1; i++)
            for(int j=0;j<len2; j++)
                tmp[i+j+1]+=num1[i]*num2[j];

        string res="";
        for(int i=len1+len2-1; i>=0; --i){
            if(i>0 && tmp[i]>9){
                tmp[i-1]+=tmp[i]/10;
                tmp[i] %= 10;
            }    
            res = char(tmp[i]+'0')+res;
        }
        
        int len=res.length()-1,i;
        for(i=0; i<len; ++i){
            if(res[i]!='0') break;
        }
        return res.substr(i);
    }
};