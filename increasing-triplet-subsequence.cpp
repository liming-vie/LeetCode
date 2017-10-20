class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size(); 
        if (n < 3)  return false;
        
        int min1=nums[0], min2;
        bool has = false;
        for (int i=1; i<n; ++i) {
            if (has && nums[i] > min2)  return true;
            if ((nums[i] > min1) && (!has || nums[i] < min2)) {
                min2 = nums[i];
                has = true;
            }
            min1 = min1 > nums[i] ? nums[i] : min1;
        }
        return false;
    }
};