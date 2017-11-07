class Solution {
public:
    vector<string> res;
    
    void check(long lower, long num) {
        long diff=num-lower;
        if (diff>1) {
            string str = to_string(lower+1);
            if (diff > 2) {
                str += "->";
                str += to_string(num-1);
            }
            res.push_back(str);
        }
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        long llower = lower;
        --llower;
        for (int i=0; i<nums.size(); ++i) {
            check(llower, nums[i]);
            llower=nums[i];
        }
        check(llower, (long)upper+1);
        return res;
    }
};