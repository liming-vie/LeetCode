class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur=0;
        for(int i=0; i<nums.size(); ++i) {
            if(cur<i)   return false;
            int tmp=nums[i] + i;
            cur=cur>tmp?cur:tmp;
        }
        return true;
    }
};