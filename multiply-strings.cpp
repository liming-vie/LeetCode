class Solution {
public:
    string multiply(string num1, string num2) {
        int l1=num1.length(), l2=num2.length();
        vector<int> res(l1+l2, 0);
        
        for (int i=0; i<l1; ++i) num1[i] -= '0';
        for (int i=0; i<l2; ++i) num2[i] -= '0';
        
        for (int i=0; i<l1; ++i) {
            for (int j=0; j<l2; ++j) {
                res[i+j] += num1[l1-i-1] * num2[l2-j-1];
            }
        }
        
        int y=0;
        for (int i=0; i<l1+l2; ++i) {
            res[i] += y;
            y=res[i] / 10;
            res[i] %= 10;
        }
        
        string str;
        int i= l2+l1-1;
        while(i>0 && !res[i])  --i;
        for (; i>=0; --i) {
            str+=(char)(res[i] + '0');
        }
        return str;
    }
};