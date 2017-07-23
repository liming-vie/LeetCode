class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {  
        // use long in case of overflow      
        long lnumerator=numerator, ldenominator=denominator;
        lnumerator = lnumerator < 0 ? -lnumerator : lnumerator;
        ldenominator = ldenominator < 0 ? -ldenominator : ldenominator;
        bool neg = ((numerator < 0) ^ (denominator < 0));
        
        string res=to_string(lnumerator/ldenominator);
        lnumerator=lnumerator%ldenominator;
        if (lnumerator == 0)
            return neg && res != "0" ? "-"+res : res;
        
        res += '.';
        map<int, int> mp;
        while(lnumerator) {
            if (mp.find(lnumerator)!=mp.end()) {
                res+=")";
                res.insert(mp[lnumerator], "(");
                break;
            } else {
                mp[lnumerator] = res.length();
            }
            
            lnumerator*=10;
            if (lnumerator < ldenominator) {
                res += "0";
                continue;  
            } 
            res+=(lnumerator/ldenominator)+'0';
            lnumerator%=ldenominator;
        }
        return neg ? "-" + res : res;
    }
};