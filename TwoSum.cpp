class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int,int> mp;
        for(int i=0; i<nums.size(); ++i)
            mp.insert(make_pair(nums[i],i));
        
        for(auto p=mp.begin(); p!=mp.end(); ++p) {
            auto t=mp.find(target-p->first);
            if(t!=mp.end()) {
                if(t==p) ++t;
                return vector<int>{p->second, t->second};
            }
        }
        return vector<int>();
    }
};