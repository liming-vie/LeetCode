class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int y=1;
        for(int i=digits.size()-1; i>=0; --i) {
            digits[i] += y;
            y=digits[i]/10;
            digits[i]%=10;
        }
        if(y) {
            digits.insert(digits.begin(), y);
        }
        return digits;
    }
};