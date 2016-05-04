class Solution {
public:
    int atoi(string str) {
        int MAX=2147483647;
        int MIN=-2147483648;
        int len=str.length();
        
        long long res=0;
        int i=0;
        bool neg=false;
        int nl=0;
        
        while(str[i]==' ') ++i;
        
        if(str[i]=='-'){
          neg=true;
          ++i;
        }else if(str[i]=='+') ++i;
        
        
        for(; i<len; ++i,++nl){
            if(str[i] <'0' || str[i]>'9')  break;
            res *= 10;
            res += str[i]-'0';
        }
        
        if(neg) res = 0-res;
        if(!neg && (nl > 10 || res>=MAX)) return MAX;
        if(nl>10 || res<=MIN) return MIN;
        return res;
    }
};