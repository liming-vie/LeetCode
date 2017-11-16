class Solution {
public:
    char arr1[5] = {'0', '1', '6', '8', '9'};
    char arr2[5] = {'0', '1', '9', '8', '6'};
    char same[3] = {'0', '1', '8'};
    
    bool valid(const string& str, const string &low, const string &high) {
        bool l = str.length()>low.length() || (str.length()==low.length()&&str>=low);
        bool r = str.length()<high.length() || (str.length()==high.length()&&str<=high);
        return l&&r;
    }
    
    int count(const string& low, const string& high, int len, string str, string rev) {
        if (len==0) {
            if (str.length() || rev.length()) {
                if (valid(str+rev, low, high))
                    return 1;
            }
            return 0;
        }
        if (len==1) {
            int res=0;
            for (int i=0; i<3; ++i) {
                if (valid(str + same[i] + rev, low, high))
                    ++res;
            }
            return res;
        }
        
        int res=0;
        for (int i=str.length()?0:1; i<5; ++i) {
            res += count(low, high, len-2, str+arr1[i], arr2[i]+rev);
        }
        return res;
    }
    
    int strobogrammaticInRange(string low, string high) {
        int res = 0;
        for (int len=low.length(); len<=high.length(); ++len) {
            res += count(low, high, len, "", "");
        }
        return res;
    }
};