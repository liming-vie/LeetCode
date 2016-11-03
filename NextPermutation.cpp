class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len=nums.size();
        int i=len-2;
        while(i>=0 && nums[i]>=nums[i+1])
            --i;
            
        if(i<0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int j=len-1;
        while(j>i && nums[j]<=nums[i])   --j;
        
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
        
        reverse(nums.begin()+i+1,nums.end());
        return;
    }
};