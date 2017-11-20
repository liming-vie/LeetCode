class Solution {
public:
    bool canPermutePalindrome(string s) {
        int sum=0;
        unordered_map<char, int> count;
        for (char c : s) {
            if (count[c]) {
                --count[c];
                --sum;
            } else {
                ++count[c];
                ++sum;
            }
        }
        return sum < 2;
    }
};