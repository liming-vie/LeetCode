class WordDistance {
public:
    unordered_map<string, vector<int>> mp;
    
    WordDistance(vector<string> words) {
        int i=0;
        for (const auto& word : words) {
            mp[word].push_back(i++);
        }
    }
    
    int shortest(string word1, string word2) {
        const auto &idx1 = mp[word1];
        const auto &idx2 = mp[word2];
        int i1=idx1.size()-1, i2=idx2.size()-1;
        int res=~(1<<31);
        while (i1>=0 && i2>=0) {
            if (idx1[i1]>idx2[i2]) {
                res = min(res, idx1[i1]-idx2[i2]);
                --i1;
            } else {
                res = min(res, idx2[i2]-idx1[i1]);
                --i2;
            }
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */