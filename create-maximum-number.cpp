class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0), cur(k);
        for (int i=max(k-(int)nums2.size(), 0); i<=min((int)nums1.size(), k); ++i) {
            const auto& num1=maxNumber(nums1, i);
            const auto& num2=maxNumber(nums2, k-i);
            int idx=0, i1=0, i2=0;
            bool flag = true;
            while (i1<num1.size() || i2<num2.size()) {
                if (i2==num2.size() || (i1<i && greater(num1, i1, num2, i2))) {
                    cur[idx] = num1[i1++];
                }
                else cur[idx] = num2[i2++];
                if (flag) {
                    if (cur[idx] > res[idx])
                        flag=false;
                    else if (cur[idx] < res[idx])
                        break;
                }
                idx++;
            }
            if (idx==k) res=cur;
        }
        
        return res;
    }
    
    bool greater(const vector<int>& num1, int v1, const vector<int>& num2, int v2) {
        int i1=v1, i2=v2;
        int n1=num1.size(), n2=num2.size();
        while (i1<n1 && i2<n2) {
            if (num1[i1]>num2[i2])  return true;
            else if (num1[i1]<num2[i2]) return false;
            ++i1, ++i2;
        }
        return i1<n1;
    }
    
    vector<int> maxNumber(const vector<int>& num, int k) {
        vector<int> res;
        if (k==0)   return res;
        
        int to_drop = num.size() - k;
        for (int n:num) {
            while (to_drop && res.size() && n > res.back()) {
                res.pop_back();
                --to_drop;
            }
            res.push_back(n);
        }
        res.resize(k);
        return res;
    }
};