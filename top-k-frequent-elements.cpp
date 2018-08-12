class Solution {
public:
    void qsort(vector<pair<int, int>>& counts, int k, int left, int right) {
        if (left >= right) {
            counts.resize(k+1);
            return;
        }
        
        int pivot = (left+right)>>1;
        auto val = counts[pivot];
        counts[pivot] = counts[right];
        int l=left, r=right;
        
        while (l<r) {
            while (l<r && counts[l].second >= val.second) ++l;
            if (l<r) counts[r--] = counts[l];
            while (l<r && counts[r].second <= val.second) --r;
            if (l<r) counts[l++] = counts[r];
        }
        counts[l] = val;
        
        if (l==k) {
            counts.resize(k+1);
            return;
        }
        if (l<k) {
            qsort(counts, k, l+1, right);
            return;
        }
        qsort(counts, k, left, l-1);
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ct;
        for (int n: nums) {
            ++ct[n];
        }
        
        vector<pair<int, int>> counts;
        for (const auto& p: ct) counts.push_back(p);
        
        qsort(counts, k-1, 0, counts.size()-1);
        
        vector<int> res;
        for (const auto&p:counts) {
            res.push_back(p.first);
        }
        return res;
    }
};