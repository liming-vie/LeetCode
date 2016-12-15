class Solution {
public:
    vector<int> grayCode(int n) {
        int size=1<<n;
        vector<int> res(size, 0);
        int idx=1;
        for(int i=0; i<n; ++i) {
            int k=1<<i;
            for(int j=idx-1; j>=0; --j) {
                res[idx++]=res[j]|k;
            }
        }
        return res;
    }
};