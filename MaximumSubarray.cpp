class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxn=1<<31;
        int sum=0;
        int n=nums.size();
        for(int i=0; i<n; ++i){
            if(sum<0)     sum=0;
            sum+=nums[i];
            if(sum>maxn)    maxn=sum;
        }
        return maxn;
    }
};