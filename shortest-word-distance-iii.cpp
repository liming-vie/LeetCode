class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int idx1=-1, idx2=-1, i=0;
        int res=words.size();
        bool same=word1==word2;
        for (const auto &word : words) {
            int tmp=idx1;
            if (word==word1) {
                if (idx2>=0)    res = min(res, i-idx2);
                idx1=i;
            }
            if (word==word2) {
                if (same && tmp>=0) res = min(res, i-tmp);
                else if (!same && idx1>=0) res = min(res, i-idx1);
                idx2=i;
            }
            ++i;
        }
        return res;
    }
};