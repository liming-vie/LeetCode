class Solution {
public:
    unordered_map<int, vector<int>> pre;
    vector<vector<string>> res;
    vector<string> cur;
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string, int> mp;
        unordered_set<string> st;
        for (int i=0; i<wordList.size(); ++i) {
            mp[wordList[i]] = i;
            st.insert(wordList[i]);
        }
        
        unordered_set<string> layer[2];
        int prei=0, curi=1;
        layer[prei].insert(beginWord);
        while(layer[prei].size()) {
            for (const auto& str : layer[prei]) {
                st.erase(str);
            }
            layer[curi].clear();
            
            for (const auto& str : layer[prei]) {
                string tmp = str;
                for (int i=0; i<str.length(); ++i) {
                    for (char c='a'; c<='z'; ++c) {
                        if (c==str[i])  continue;
                        tmp[i] = c;
                        
                        if (st.find(tmp) == st.end()) 
                            continue;
                        pre[mp[tmp]].push_back(mp[str]);
                        layer[curi].insert(tmp);
                    }
                    tmp[i] = str[i];
                }
            }
            
            if (layer[curi].find(endWord) != layer[curi].end()) break;
            swap(prei, curi);
        }
        
        if (!layer[prei].size())    return res;
        generate(wordList, mp[endWord]);
        return res;
    }
    
    
    void generate(const vector<string>& wordList, int vi) {
        cur.push_back(wordList[vi]);
        if (pre[vi].size()) {
            for (int i : pre[vi])
                generate(wordList, i);
        } else {
            vector<string> tmp(cur);
            reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
        }
        cur.pop_back();
    }
};