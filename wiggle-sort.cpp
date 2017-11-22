class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        if (n<2)    return;
        
        auto mid_ptr = nums.begin() + (n>>1);
        nth_element(nums.begin(), mid_ptr, nums.end());
        int mid=*mid_ptr;
        
        #define A(i) nums[(1+(i<<1))%(n|1)]
        int l=0, r=n-1, i=0;
        while (i<=r) {
            if (A(i)>mid) {
                swap(A(i++), A(l++));
            } else if (A(i)<mid) {
                swap(A(i), A(r--));
            } else ++i;
        }
    }
};