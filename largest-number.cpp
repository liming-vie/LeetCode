class Solution {
public:
    static bool cmp(const string& a, const string& b) {
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> strs(nums.size());
        stringstream ss;
        for(int i=0; i<nums.size(); ++i) {
            ss<<nums[i];
            strs[i]=ss.str();
            ss.str("");
        }
        sort(strs.begin(), strs.end(),cmp);
        
        for(const auto&str:strs) {
            ss<<str;
        }
        
        string res = ss.str();
        if (res.length() == 0 || res[0]=='0')   return "0";
        return res;
    }
};