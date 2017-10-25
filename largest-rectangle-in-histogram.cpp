class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int n=height.size();
        int res=0;
        stack<int> st;
        for(int i=0; i<n; ++i) {
            while(!st.empty() && height[st.top()] > height[i]) {
                int t=st.top();
                st.pop();
                t=height[t]*(st.empty()?i:(i-st.top()-1));
                res=t>res?t:res;
            }
            st.push(i);
        }
        return res;
    }
    
};