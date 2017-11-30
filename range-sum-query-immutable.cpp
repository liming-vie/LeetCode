class NumArray {
public:
    NumArray(vector<int> nums) {
        int n=nums.size();
        if (!n) return;
        
        sums.resize(n+1);
        sums[0]=0;
        for (int i=1; i<=n; ++i) 
            sums[i] = sums[i-1]+nums[i-1];
    }
    
    int sumRange(int i, int j) {
        return sums[j+1]-sums[i];
    }
    
    vector<long> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */