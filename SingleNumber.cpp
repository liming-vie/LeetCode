class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int test=0;
        for(auto num:nums)
        	test^=num;
        return test;
    }
};