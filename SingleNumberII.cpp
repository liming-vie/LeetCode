class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // count 1's in each bit
        int count[32]={0};
        for(auto n:nums) {
            for(int i=0; i<32; ++i)
                count[i]+=(n>>i)&1;
        }
        int ret=0;
        for(int i=0; i<32; ++i) {
        	ret|=(count[i]%3)<<i;
        }
        return ret;
    }
};