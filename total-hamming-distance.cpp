class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, k=1;
        int count[2];
        for (int i=0; i<32; ++i) {
            count[0]=count[1]=0;
            for (int j=0; j<nums.size(); ++j) {
                ++count[(nums[j]&k)?1:0];
            }
            res += count[0] * count[1];
            k<<=1;
        }
        return res;
    }
};