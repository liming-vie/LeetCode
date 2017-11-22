class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l=1, r=nums.size()-1, mid, count;
        while (l<r) {
            mid = l+((r-l)>>1);
            count=0;
            for (int n:nums) {
                count += (n<=mid);
            }
            if (count <= mid) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};