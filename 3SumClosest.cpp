class Solution {
public:
#define ADDL() {++l; while(l<r && nums[l-1] == nums[l])  ++l;}
#define MINUSR() {--r; while(l<r && nums[r+1] == nums[r]) --r;}
    
    inline int iabs(int a) {
        return a < 0 ? -a : a;
    }
        
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int min=~(1<<31), res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; ++i) {
            if (i && nums[i] == nums[i-1])  continue;
            int l=i+1,r=n-1;
            int t=target-nums[i];
            while(l<r) {
                int sum = nums[l]+nums[r];
                if(sum < t) 
                    ADDL()
                else if(sum > t)
                    MINUSR()
                else return target;
                int diff = iabs(t-sum);
                if(diff < min) {
                    min=diff;
                    res=sum + nums[i];
                }
            }
        }
        return res;
    }
};