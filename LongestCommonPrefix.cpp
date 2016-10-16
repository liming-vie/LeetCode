class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string res=n > 0 ? strs[0] : "";
        int len=res.length();
        for(int i=1; i<n; ++i) {
            int l=strs[i].length();
            int j=0;
            while(j<len && j<l && strs[i][j] == res[j]) ++j;
            if(j<len) {
                len=j;
                res = res.substr(0,len);
            }
        }
        return res;
    }
};