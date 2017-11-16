class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int i1=-1, i2=-1, i=0;
        int res=words.size();
        for (const string& word : words) {
            if (word == word1) {
                if (i2>=0) {
                    res = min(res, i-i2);
                }
                i1=i;
            } else if (word == word2) {
                if (i1>=0) {
                    res = min(res, i-i1);
                }
                i2=i;
            }
            ++i;
        }
        return res;
    }
};