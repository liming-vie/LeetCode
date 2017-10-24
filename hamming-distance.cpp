class Solution {
public:
    int hammingDistance(int x, int y) {
        int res=0;
        for (int i=0; i<32; ++i) {
            res += (((1<<i)&x)^((1<<i)&y))?1:0;
        }
        return res;
    }
};