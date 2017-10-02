class Solution {
public:
    string concat(const string&a, const string&b) {
        if (a.length() && b.length()) {
            return a+" "+b;
        }
        return a+b;
    }
    
    string numberToWords(int num) {
        if (!num)   return digit[0];
        
        string res;
        int k = 0;
        while(num) {
            res = concat(convert(num%1000, k), res);
            ++k;
            num/=1000;
        }
        return res;
    }
    
    string convert(int num, int k) {
        if (!num) return "";
        
        string res;
        if (num >= 100) {
            res = concat(digit[num/100], tens[10]);
        }
        int tmp=num%100;
        if (tmp) {
            if (tmp < 10) {
                res = concat(res, digit[tmp]);
            }
            else if (tmp < 20) {
                res = concat(res, teens[tmp-10]);
            }
            else if (num % 10) {
                res = concat(res, concat(tens[tmp/10], digit[tmp%10]));
            }
            else {
                res = concat(res, tens[tmp/10]);   
            }
        }  
        return concat(res, units[k]);
    }
    
private:
    string digit[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string teens[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[11] = {"","Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred"};
    string units[4] = {"", "Thousand","Million", "Billion"};
};