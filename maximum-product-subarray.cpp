#define MAX(a,b)	((a)>(b)?(a):(b))
#define MIN(a,b)	((a)<(b)?(a):(b))
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(!n)  return 0;
        
        int res=nums[0];
        int min=nums[0], max=nums[0];
        for(int i=1; i<n; ++i) {
            int t1=min*nums[i];
            int t2=max*nums[i];
            min=MIN(nums[i], MIN(t1,t2));
            max=MAX(nums[i], MAX(t1,t2));
            res=MAX(max, res);
        }
        return res;
    }
};