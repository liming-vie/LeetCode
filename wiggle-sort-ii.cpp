// refer to  https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        auto midptr = nums.begin() + (n >> 1);
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        // re-arrange the index, when n=10, the new index is 1 3 5 7 9 0 2 4 6 8
        #define A(i)    (nums[(1+((i)<<1)) % (n|1)])
        // three way partition
        int l=0, r=n-1;
        int i=0;
        while(i<=r) {
            if(A(i)>mid) 
                swap(A(i++),A(l++));
            else if(A(i)<mid) 
                swap(A(i),A(r--));
            else    ++i;
        }
    }
};
