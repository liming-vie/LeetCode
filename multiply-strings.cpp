class Solution {
public:
    string multiply(string num1, string num2) {
        int l1=num1.length(), l2=num2.length();
        for(int i=0; i<l1; ++i) num1[i]-='0';
        for(int i=0; i<l2; ++i) num2[i]-='0';
        
        vector<int> res(l1+l2+1,0);
        for(int i=l1-1; i>=0; --i) 
            for(int j=l2-1; j>=0; --j) 
                res[i+j+1]+=num1[i]*num2[j];
        
        int t=0;
        for(int i=l1+l2-1; i>=0; --i) {
            res[i]+=t;
            t=res[i]/10;
            res[i]%=10;
        }
        
        string str="";
        for(int i=l1+l2-1; i>=0; --i)
            str=(char)('0'+res[i])+str;
        
        for(int i=0; i<l1+l2; ++i) {
            if(str[i] != '0')
                return str.substr(i);
        }
        return "0";
    }
};