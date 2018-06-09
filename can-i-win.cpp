class Solution {
public:
    std::map<int, bool> win;
    
    bool helper(int mask, int max_i, int target) {
        if (win.find(mask) != win.end())  return win[mask];
        for (int i=1; i<=max_i; ++i) {
            int t=(1<<i);
            if (t&mask) continue;
            if (target <= i) {
                return win[mask] = true;
            }
            if (!helper(mask|t, max_i, target-i)) {
                return win[mask] = true;
            }
        }
        return win[mask] = false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) {
            return true;
        }
        int sum = ((maxChoosableInteger * (maxChoosableInteger+1))>>1);
        if (sum < desiredTotal) {
            return false;
        }
        win.clear();
        return helper(0, maxChoosableInteger, desiredTotal);
    }
};