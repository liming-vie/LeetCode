class Solution {
public:
    char same[3] = {'0','1','8'};
    vector<string> res;
    
    void func(int len, string str, string rev) {
        if (len==0) {
            if (str.length() || rev.length()) {
                res.push_back(str+rev);
            }
            return;
        }
        
        if (len==1) {
            for (int i=0; i<3; ++i) {
                res.push_back(str+same[i]+rev);
            }
            return;
        }
        
        for (int i=str.length()>0?0:1; i<3; ++i) {
            func(len-2, str+same[i], same[i]+rev);
        }
        
        func(len-2, str+'6', '9'+rev);
        func(len-2, str+'9', '6'+rev);
    }
    
    vector<string> findStrobogrammatic(int n) {
        if (n==0)   return vector<string>();
        string s, r;
        func(n, s, r);
        return res;
    }
};