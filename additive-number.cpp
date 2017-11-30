class Solution {
public:
    bool check(const string& num, int ni, int vi, const string& a, const string& b) {
        if (vi==num.length()) {
            return ni>=3;
        }
        
        const auto& sum=addString(a, b);
        if (num.substr(vi, sum.length()) != sum)
            return false;
        
        return check(num, ni+1, vi+sum.length(), b, sum);
    }
    
    string addString(const string& a, const string& b) {
        string res;
        int i=a.length()-1, j=b.length()-1;
        int y=0;
        while (i>=0 || j>=0 || y) {
            int t=y;
            t += (i>=0) ? a[i]-'0' : 0;
            t += (j>=0) ? b[j]-'0' : 0;
            --i, --j;
            y=t/10;
            res+=((t%10)+'0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool isAdditiveNumber(string num) {
        int len=num.length();
        if (len < 3)    return false;
        
        for (int i=0; i<(num[0]=='0'?1:len-1); ++i) {
            const auto a=num.substr(0, i+1);
            for (int j=i+1; j<(num[i+1]=='0'?i+2:len); ++j) {
               if (check(num, 2, j+1, a, num.substr(i+1, j-i)))
                   return true;
            }
        }
        return false;
    }
};