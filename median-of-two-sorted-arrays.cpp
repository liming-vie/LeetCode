class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())    swap(nums1, nums2);
        int n=nums1.size(), m=nums2.size();
        
        int l=0, r=n;
        int half = (n+m+1)>>1;
        while (l<=r) {
            int vi=(l+r)>>1;
            int vj=half-vi;
            if (vi<n && nums1[vi] < nums2[vj-1]) {
                l = vi+1;
            } else if (vi>0 && nums1[vi-1] > nums2[vj]) {
                r = vi-1;
            } else {
                double leftmax;
                if (vi == 0)    leftmax = nums2[vj-1];
                else if (vj==0) leftmax = nums1[vi-1];
                else leftmax = max(nums2[vj-1], nums1[vi-1]);
                
                if ((n + m) & 1)    return leftmax;
                
                double rightmin;
                if (vi==n)  rightmin = nums2[vj];
                else if (vj==m) rightmin = nums1[vi];
                else rightmin = min(nums1[vi], nums2[vj]);
                
                return (leftmax + rightmin)/2;
            }
        }
        return 0.0;
    }
};