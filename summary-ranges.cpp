class Solution {
public:
    string make(int start, int end) {
        string res = to_string(start);
        if (start==end) return res;
        return res + "->" + to_string(end);
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n=nums.size();
        if (!n) return res;
        
        nums.resize(n+1);
        int start = nums[0];
        for (int i=1; i<=n; ++i) {
            if (i==n || nums[i]>(long)nums[i-1]+1) {
                res.push_back(make(start, nums[i-1]));
                start = nums[i];
            }
        }
        return res;
    }
};