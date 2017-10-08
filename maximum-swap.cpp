#define MAX(a,b) (a)>(b)?(a):(b)

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        while(num) {
            digits.push_back(num%10);
            num/=10;
        }
        
        int curmax = 0, maxi;
        int toswap[2] = {-1,-1};
        
        for (int i=0; i<digits.size(); ++i) {
            if (curmax > digits[i]) {
                toswap[0] = i;
                toswap[1] = maxi;
            } else if (digits[i] > curmax) {
                curmax = digits[i];
                maxi = i;
            }
        }
        
        if (toswap[0] != -1) {
            swap (digits[toswap[0]], digits[toswap[1]]);   
        }
        int res = 0;
        for (int i=digits.size()-1; i>=0; --i) {
            res *= 10;
            res += digits[i];
        }
        return res;
    }
};