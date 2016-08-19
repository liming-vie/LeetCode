class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1);
        bool odd=false;
        for(int i=0; i<=num;++i) {
            if(odd){
                ret[i] = ret[i>>1] + 1;
            }
            else {
                ret[i] = ret[i>>1];
            }
            odd = !odd;
        }
        return ret;
    }
};