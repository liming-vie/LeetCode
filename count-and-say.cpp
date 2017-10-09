class Solution {
public:
    string countAndSay(int n) {
        string s[2] = {"1"};
        int idx=0, prev=1;
        while (--n) {
            swap(idx, prev);
            s[idx].clear();
            int count = 1;
            for (int i=1; i<=s[prev].length(); ++i) {
                if (i<s[prev].length() && s[prev][i] == s[prev][i-1]) {
                    ++count;
                } else {
                    s[idx] += (count + '0');
                    s[idx] += s[prev][i-1];
                    count = 1;
                }
            }
        }
        return s[idx];
    }
};