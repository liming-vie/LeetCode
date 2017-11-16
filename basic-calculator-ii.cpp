class Solution {
public:
    int compute(int a, int b, char sign) {
        switch (sign) {
            case '-':   return a-b;
            case '*':   return a*b;
            case '/':   return a/b;
            default:    return a+b;
        }
    }
    
    int calculate(string s) {
        char sign=0, psign=0, c;
        int res=0, pres=0, cur=0;
        for (char c : s) {
            switch (c) {
                case ' ':
                    break;
                case '*':
                case '/':
                    if (sign=='+' || sign=='-') {
                        if (psign) res = compute(pres, res, psign);
                        pres = res;
                        psign = sign;
                        sign = 0;
                        res = cur;
                    } else {
                        res = compute(res, cur, sign);
                    }
                    sign=c;
                    cur = 0;
                    break;
                case '+':
                case '-':
                    res = compute(res, cur, sign);
                    if (psign) {
                        res = compute(pres, res, psign);
                        pres = psign = 0;
                    }
                    sign = c;
                    cur = 0;
                    break;
                default:
                    cur *= 10;
                    cur += c-'0';
            }
        }
        res = compute(res, cur, sign);
        if (psign) {
            res = compute(pres, res, psign);
            pres = psign = 0;
        }
        
        return res;
    }
};