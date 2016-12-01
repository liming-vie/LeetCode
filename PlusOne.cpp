class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        digits[n-1]++;
        int y=0;
        for(int i=n-1; i>=0; --i){
            digits[i]+=y;
            y=digits[i]/10;
            digits[i]%=10;
        }
        if(y>0) digits.insert(digits.begin(),y);
        return digits;
    }
};