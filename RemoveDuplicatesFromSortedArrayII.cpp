class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n < 3)   return n;
        int count=1;
        int curn=nums[0];
        int len=1;
        for(int i=1; i<n; ++i){
            if(curn!=nums[i]){
                curn=nums[i];
                count=1;
                nums[len++]=curn;
            }else if(count<2){
                nums[len++]=curn;
                ++count;
            }
            
        }
        return len;
    }
};