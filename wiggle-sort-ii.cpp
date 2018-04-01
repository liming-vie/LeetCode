// refer to  https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        
        auto mid_ptr = nums.begin() + (n>>1);
        nth_element(nums.begin(), mid_ptr, nums.end());
        int mid=*mid_ptr;
        
        int l=0, i=0, r=n-1;
        // re-arrange the index, when n=10, the new index is 1 3 5 7 9 0 2 4 6 8
        #define A(i) (nums[((i<<1)+1) % (n|1)])
        // three way partition
        while (i<=r) {
            if (A(i)<mid) {
                swap(A(i), A(r--));
            } else if (A(i)>mid) {
                swap(A(i++), A(l++));
            } else ++i;
        }
    }
};