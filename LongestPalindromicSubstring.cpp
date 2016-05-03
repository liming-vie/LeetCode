// learn from http://articles.leetcode.com/longest-palindromic-substring-part-ii
class Solution {
public:
    string preProcess(string&s) {
        int len=s.length();
        if(len==0)  return "^$";
        // add ^ and $ to avoid boundary check
        stringstream ss;
        ss << "^";
        for(int i=0; i<len; ++i) {
            ss << '#' << s[i];
        }
        ss << "#$";
        return ss.str();
    }
    string longestPalindrome(string s) {
        string str = preProcess(s);
        int len=str.length();
        int *p = new int[len];
        int center=0,right=0;
        int mirror;
        int upper = len-1;
        for(int i=1; i<upper; ++i) {
            mirror = (center << 1) - i;
            p[i] = (right>i) ? min(right-i, p[mirror]) : 0;
            // expand length
            while(str[i+p[i]+1] == str[i-p[i]-1])
                ++p[i];
            if(p[i] + i > right) {
                right = p[i] + i;
                center=i;
            }
        }
        
        right=0;
        center=0;
        for(int i=1; i<upper; ++i) {
            if(p[i] > right) {
                right=p[i];
                center = i;
            }
        }
        return s.substr((center-right-1)>>1 ,right);
    }
};