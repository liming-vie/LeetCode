class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> st;
        for (int n:nums) {
           auto l=st.lower_bound(n) ;
            if (l!=st.end()) {
                st.erase(l);
            }
            st.insert(n);
        }
        return st.size();
    }
};