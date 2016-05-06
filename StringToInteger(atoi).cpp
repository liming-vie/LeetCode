class Solution {
public:
    int myAtoi(string str) {
        int MIN=1<<31;
        int MAX=~MIN;
        
        int len=str.length();
        int idx=0;
        while(idx<len && str[idx]==' ') ++idx;
        long result=0;
        bool negative = false;
        if(str[idx] == '-') {
            negative=true;
            ++idx;
        }
        else if(str[idx] == '+')
            ++idx;
            
        long res=0;
        int l=0;
        while(idx<len) {
            if(str[idx]<'0' || str[idx]>'9') {
                break;
            }
            res = res*10+(str[idx]-'0');
            ++idx;
            if(++l==11) return negative?MIN:MAX;
        }
        res = negative?-res:res;
        return res < MIN ? MIN : (res > MAX ? MAX : res);
    }
};