class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        ret.reserve(num);
        int d[4]={0,1,0,1};
        int cur=0, next=0, idx=0;
        for(int i=0; i<=num; ++i) {
            cur += d[next++];
            ret.push_back(cur);
            if(next == 4) {
                cur=ret[++idx];
                next=0;
            }
        }
        return ret;
    }
};