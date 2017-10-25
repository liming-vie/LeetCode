class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        st.push(make_pair(-1, 0));
        heights.push_back(0);
        int res = 0;
        for (int i=0; i<heights.size(); ++i) {
            while (st.top().second > heights[i]) {
                int vi = st.top().first, hi=st.top().second;
                st.pop();
                res = max(res, hi * (i-st.top().first-1));
            }
            st.push(make_pair(i, heights[i]));
        }
        return res;
    }
};