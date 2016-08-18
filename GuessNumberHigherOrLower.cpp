// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l=1,r=n;
        int mid;
        while(l<r) {
            mid=l+((r-l)>>1);
            switch(guess(mid)){
                case -1:
                    r=mid-1;
                    break;
                case 1:
                    l=mid+1;
                    break;
                case 0:
                    return mid;
            }
        }
        return l;
    }
};