class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=1<<31;
        int cur=0;
        for(auto num:nums) {
            cur=cur<0?0:cur;
            cur+=num;
            res=res>cur?res:cur;
        }
        return res;
    }
};