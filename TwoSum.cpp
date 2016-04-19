class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        if(nums.size()<=1)  return res;
        
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); ++i){
            mp[nums[i]]=i;
        }
        
        int n=(nums.size());
        for(int i=0; i<n; ++i){
            if(mp.find(target-nums[i])!=mp.end()){
                int a=mp[target-nums[i]];
                int b=i;
                if(a==i)    continue;
                if(a<b){
                    res.push_back(a+1);
                    res.push_back(b+1);
                }else{
                    res.push_back(b+1);
                    res.push_back(a+1);
                }
                return res;
            }
        }
    }
};