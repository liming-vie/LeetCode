class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, mid;
        while(l<=r) {
            mid=l+((r-l)>>1);
            if(nums[mid]==target) {
                int b=mid-1,e=mid;
                while(b>=0 && nums[b]==target)  --b;
                while(e<nums.size() && nums[e]==target) ++e;
                return vector<int>{b+1,e-1};
            }
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        return vector<int>{-1,-1};
    }
};