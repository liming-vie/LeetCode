class Solution {
public:
    struct Num {
        int val;
        int idx;
    };
    static bool comp(Num &a,Num &b){
      return a.val < b.val;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int size=nums.size();
        if(size <= 1)   return vector<int>();
        
        Num *data = new Num[size];
        for(int i=0; i<size; ++i) {
            data[i] = {nums[i], i};
        }
        sort(data, data + size, comp);
        
        int l=0, r=size-1;
        int tmp;
        while(l<r) {
            tmp=data[l].val + data[r].val;
            if(tmp < target) ++l;
            else if(tmp > target) --r;
            else break;
        }
        int idx1 = data[l].idx;
        int idx2 = data[r].idx;
        return idx1 < idx2 ? vector<int>{idx1, idx2} : vector<int>{idx2, idx1};       
    }
};