class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(!n)  return 0;
        int d=1, p=1;
        for(int i=1; i<n; ++i) {
            if(nums[i] > nums[i-1])
                d=p+1;
            else if(nums[i] < nums[i-1]) 
                p=d+1;
        }
        return max(d,p);
    }
};