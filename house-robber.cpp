class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = 0, norob = 0;
        for (int n:nums) {
            int tmp = max(rob, norob);
            rob = max(norob+n, rob);
            norob = tmp;
        }
        return max(norob, rob);
    }
};