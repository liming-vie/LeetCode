class Solution {
public:
    unordered_map<string, vector<string>> pre;
    vector<vector<string>> res;
    vector<string> cur;

    void generate(string str) {
        cur.push_back(str);
        if(!pre[str].size()) {
            vector<string> tmp(cur);
            reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
        } else {
            for(auto s:pre[str]) {
                generate(s);
            }
        }
        cur.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        wordList.insert(endWord);
        unordered_set<string> layer[2]; // instead of queue
        layer[0].insert(beginWord);
        int curi=1, prei=0;
        int len=beginWord.size();
        while(layer[prei].size()) {
            for(auto str : layer[prei]) {
                wordList.erase(str);
            }
            layer[curi].clear();
            for(auto str:layer[prei]) {
                for(int i=0; i<len; ++i) {
                    string tmp=str;
                    char c=str[i];
                    for(int j='a'; j<='z'; ++j) {
                        if(c==j)    continue;
                        str[i]=j;
                        if(wordList.find(str)!=wordList.end()) {
                            layer[curi].insert(str);
                            pre[str].push_back(tmp);
                        }
                    }
                    str[i]=c;
                }
            }
            if(layer[curi].find(endWord)!=layer[curi].end())    break;
            curi = !curi; prei = !prei;
        }
        if(!layer[prei].size()) return res;
        generate(endWord);
        return res;
    }
};