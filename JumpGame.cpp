class Solution {
public:
    bool canJump(vector<int >& nums) {
        int max=0;
        int n=nums.size();
        for(int i=0; i<n; ++i){
            if(i>max)   return false;
            int tmp=nums[i]+i;
            max=tmp>max?tmp:max;
            if(max>=n-1)    return true;
        }
        return false;
    }
};