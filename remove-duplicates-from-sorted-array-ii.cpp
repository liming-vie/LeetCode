class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)   return nums.size();
        
        int idx=0;
        int count=1;
        for(int i=1; i<nums.size(); ++i) {
            if(nums[i]!=nums[idx]) {
                count=0;
            } else if (count==2)
                continue;
            
            ++count;
            nums[++idx]=nums[i];
        }
        return idx+1;
    }
};