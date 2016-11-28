class Solution {
public:
    int jump(vector<int>& nums) {
        int max=0;
        int curm=0;
        int step=0;
        int n=nums.size();
        for(int i=0; i<n; ++i){
            if(curm<i){
                ++step;
                curm=max;
                if(curm>=n-1)   return step;
            }
            int tmp=nums[i]+i;
            max=max<tmp?tmp:max;
        }
        return 0;
    }
};