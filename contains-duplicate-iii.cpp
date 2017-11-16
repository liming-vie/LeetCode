class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long> st;
        for (int i=0; i<nums.size(); ++i) {
            if (i>k)    st.erase(st.find(nums[i-k-1]));
            
            const auto& lower = st.lower_bound((long)nums[i]-t);
            if (lower!=st.end() && abs(*lower - nums[i]) <= t) {
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
    }
};