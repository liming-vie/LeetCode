class Solution {
public:
    int happySum(int n) {
        int sum=0;
        while (n) {
            sum += pow(n%10, 2);
            n/=10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow=n, fast=n;
        do {
            slow = happySum(slow);
            fast = happySum(fast);
            fast = happySum(fast);
        } while (slow!=fast);
        
        return slow==1;
    }
};