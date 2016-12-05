class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(r>=0 && nums[r]==2)   --r;
        while(l<=r && nums[l]==0)   ++l;
        
        int p=l,tmp;
        while(l<r && p>=l && p<=r){
            if(nums[p]==0){
                if(p==l)    ++p;
                else{
                   tmp=nums[p];
                   nums[p]=nums[l];
                   nums[l]=tmp;
                }
                ++l;
            }
            else if(nums[p]==2){
                if(p==r)    ++p;
                else{
                    tmp=nums[p];
                    nums[p]=nums[r];
                    nums[r]=tmp;
                }
                --r;
            }
            else    ++p;
        }
    }
};