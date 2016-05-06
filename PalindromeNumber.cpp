class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int y=0;
        int tmp=x;
        while(x) {
            y=y*10+x%10;
            x/=10;
        }
        return (tmp==y);
    }
};