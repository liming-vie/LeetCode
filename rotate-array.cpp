class Solution {
public:
    inline int gcd(int a, int b) {
        while (b) {
            int t=a%b;
            a=b;
            b=t;
        }
        return a;
    }
    
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if (!n) return;
        
        k %= nums.size();
        if (!k) return;
        
        for (int i=0; i<gcd(n, k); ++i) {
            int cur=nums[i];
            int idx=(i+k)%n;
            while (idx != i) {
                swap(cur, nums[idx]);
                idx = (idx+k)%n;
            }
            nums[i]=cur;
        }
    }
};