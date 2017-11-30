class NumArray {
public:    
    NumArray(vector<int> nums) : n(nums.size()) {
        if (!n) return;
        int k=1;
        while ((1<<k)<n) ++k;
        sums = vector<long>(1<<(k+1));
        build(nums, 1, 0, n-1);
    }
    
    void build(const vector<int>& nums, int vi, int left, int right) {
        if (left==right) {
            sums[vi] = nums[left];
            return ;
        }
        int mid=left+((right-left)>>1);
        int l=vi<<1, r=l+1;
        build(nums, l, left, mid);
        build(nums, r, mid+1, right);
        sums[vi] = sums[l]+sums[r];
    }
    
    void update(int vi, int left, int right, int i, int val) {
        if (left==right) {
            sums[vi]=val;
            return;
        }
        int mid=left+((right-left)>>1);
        int l=vi<<1, r=l+1;
        if (i<=mid) {
            update(l, left, mid, i, val);
        } else update(r, mid+1, right, i, val);
        sums[vi] = sums[l] + sums[r];
    }
    
    void update(int i, int val) {
        update(1, 0, n-1, i, val);
    }
    
    long query(int vi, int left, int right, int i, int j) {
        if (left==i && j==right)    return sums[vi];
        
        int mid = left + ((right-left)>>1);
        int l=vi<<1, r=l+1;
        if (j<=mid) {
            return query(l, left, mid, i, j);
        } else if (i>mid) {
            return query(r, mid+1, right, i, j);
        } else return query(l, left, mid, i, mid) + query(r, mid+1, right, mid+1, j);
    }
    
    int sumRange(int i, int j) {
        return query(1, 0, n-1, i, j);
    }
    
    int n;
    vector<long> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */