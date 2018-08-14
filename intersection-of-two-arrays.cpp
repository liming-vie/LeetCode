class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        for (int n:nums1) st.insert(n);
        
        vector<int> res;
        for (int n:nums2) {
            if (st.find(n)!=st.end()) {
                st.erase(n);
                res.push_back(n);
                if (st.empty()) break;
            }
        }
        return res;
    }
};
