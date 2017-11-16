class Solution {
public:
    inline bool isPowerOfFour(int num) {
        return ((num & 0x55555555) != 0) && ((num | (num-1)) == ((num<<1)-1));
    }
};