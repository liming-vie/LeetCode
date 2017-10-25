class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size())   return 0;
        int tail=0;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] == nums[tail])
                continue;
            nums[++tail]=nums[i];
        }
        return tail+1;
    }
};