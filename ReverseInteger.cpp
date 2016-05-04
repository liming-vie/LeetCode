class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if(x<0) {
            negative = true;
            x = -x;
        }
        long long ret = 0;
        while(x) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        if(negative)    ret = -ret;
        return (ret > (~(1<<31)) || ret < (1<<31)) ? 0 : ret;
    }
};