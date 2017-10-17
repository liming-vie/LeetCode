class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if (n < k*3)    return vector<int>();
        
        vector<int> sums(n, 0);
        sums[0] = nums[0];
        for (int i=1; i<n; ++i) {
            sums[i] = sums[i-1] + nums[i];
        }
        
        int maxsum = sums[k-1], tmp;
        vector<int> left(n, 0);
        for (int i=k; i<n; ++i) {
            tmp = sums[i] - sums[i-k];
            if (tmp > maxsum) {
                left[i] = i-k+1;
                maxsum = tmp;
            } else {
                left[i] = left[i-1];
            }            
        }
        
        vector<int> right(n, n-k);
        maxsum = sums[n-1]-sums[n-k-1];
        for (int i=n-k-1; i>=0; --i) {
            tmp = sums[i+k-1] - (i>0?sums[i-1]:0);
            if (tmp > maxsum) {
                right[i] = i;
                maxsum = tmp;
            } else {
                right[i] = right[i+1];
            }
        }
        
        maxsum=0;
        vector<int> res(3,0);
        for (int i=k; i<=n-(k<<1); ++i) {
            tmp = (sums[i+k-1]-sums[i-1]) + sums[left[i-1]+k-1] - sums[left[i-1]-1] + sums[right[i+k]+k-1] - sums[right[i+k]-1];
            if (tmp > maxsum) {
                maxsum=tmp;
                res[0] = left[i-1];
                res[1] = i;
                res[2] = right[i+k];
            }
        }
        
        return res;
    }
};