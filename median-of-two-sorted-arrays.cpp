class Solution {
public:
    double findKthNumber(int* nums1, int size1, int* nums2, int size2, int k) {
        if(size1 > size2)   return findKthNumber(nums2, size2, nums1, size1, k);
        if(size1 == 0)  return nums2[k-1];
        if(k==1)    return *nums1 < *nums2 ? *nums1 : *nums2;
        int mid1 = k >> 1;
        mid1 = mid1 > size1 ? size1 : mid1;
        int mid2 = k-mid1;
        int n1 = nums1[mid1-1], n2 = nums2[mid2-1];
        if(n1 < n2) 
            return findKthNumber(nums1+mid1, size1-mid1, nums2, size2, k-mid1);
        if(n1 > n2) 
            return findKthNumber(nums1, size1, nums2+mid2, size2-mid2, k-mid2);
        return n1;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        int mid = (s1+s2)>>1;
        if((s1 + s2) & 1){
            return findKthNumber(nums1.data(), s1, nums2.data(), s2, mid + 1);
        }
        return (findKthNumber(nums1.data(), s1, nums2.data(), s2, mid + 1) + findKthNumber(nums1.data(), s1, nums2.data(), s2, mid)) / 2;
    }
};