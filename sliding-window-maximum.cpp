class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size() < k || k==0)    return res;
        
        deque<int> qi;
        for (int i=0; i<nums.size(); ++i) {
            if (!qi.empty() && i-qi.front()>=k) {
                qi.pop_front();
            }
            while (!qi.empty() && nums[qi.back()]<=nums[i]) {
                qi.pop_back();
            }
            qi.push_back(i);
            if (i>=k-1) {
                res.push_back(nums[qi.front()]);
            }
        }
        return res;
    }
};