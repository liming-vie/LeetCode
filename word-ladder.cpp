class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for (const auto& word : wordList)
            st.insert(word);
        st.erase(beginWord);
        
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        while (!q.empty()) {
            auto &kv = q.front();
            for (int i=0; i<kv.first.length(); ++i) {
                char ori = kv.first[i];
                for (char c='a'; c<='z'; ++c) {
                    if (c==ori)  continue;
                    kv.first[i] = c;
                    
                    if (st.find(kv.first) == st.end())  continue;
                    st.erase(kv.first);
                    
                    if (kv.first == endWord)
                        return kv.second + 1;
                    q.push(make_pair(kv.first, kv.second+1));
                }
                kv.first[i] = ori;
            }
            q.pop();
        }
        return 0;
    }
};