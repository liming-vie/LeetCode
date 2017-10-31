// label the exist index number as minus
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; ++i) {
            if(nums[i]<=0)
                nums[i] = n+1;
        }
        for(int i=0; i<n; ++i) {
            int v=abs(nums[i]);
            if(v>0 && v<=n && nums[v-1] > 0)
                nums[v-1]=-nums[v-1];
        }
        for(int i=0; i<n; ++i) 
            if(nums[i] > 0)
                return i+1;
        return n+1;
    }
};