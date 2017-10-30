class Solution {
public:
    int jump(vector<int>& nums) {
        int res=0, cur=0, next=0, n=nums.size();
        for (int i=0; i<n; ++i) {
            if (cur < i) {
                ++res;
                cur=next;
            }
            next = max(next, i+nums[i]);
        }
        return res;
    }
};