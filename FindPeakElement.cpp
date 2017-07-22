class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int l = 0, r = nums.size() - 1, mid;
      while (l<r) {
        mid = (l+r)>>1;
        if (nums[mid] < nusm[mid+1]) {
          l = mid+1;
        } else {
          r = mid;
        }
      }
      return l;
    }
};
