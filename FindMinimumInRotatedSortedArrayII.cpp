class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<=r) {
        	while(l<r && nums[l]==nums[l+1])	++l;
        	while(l<r && nums[r]==nums[r-1])	--r;
        	int mid=(l+r)>>1;
        	if(nums[l]>nums[mid])	r=mid;
        	else if(nums[mid]>nums[r])	l=mid+1;
        	else return nums[l];
        }
        return nums[l];
    }
};