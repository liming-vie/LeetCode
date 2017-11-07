class Solution {
public:
    void reverseWords(vector<char>& str) {
        int start=0;
        for (int i=0; i<=str.size(); ++i) {
            if (i==str.size() || str[i]==' ') {
                if (start+1<i)
                    reverse(str.begin()+start, str.begin()+i);
                start=i+1;
            }
        }
        reverse(str.begin(), str.end());
    }
};