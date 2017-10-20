class AutocompleteSystem {
    struct Trie {
        Trie() : end(false) {}
        bool end;
        map<string, int> counts;
        map<char, Trie> next;
    };
    
    struct PairCmp {
        bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
            if (a.second == b.second)   return a.first < b.first;
            return a.second > b.second;
        }
    };
    
    Trie head;
    
    Trie* move;
    string search;
    priority_queue<pair<string, int>, vector<pair<string, int>>, PairCmp> pq;
    
    inline Trie* next(Trie* cur, char c) {
        if (cur->next.find(c) == cur->next.end()) {
            cur->next[c] = Trie();
        }
        return &(cur->next[c]);
    }
    
    void add(const string& str, int count=1) {
        if (str.length() == 0)  return;
        
        auto move = &head;
        for (int i=0; i<str.length(); ++i) {
            move = next(move, str[i]);
            if (i<str.length()) {
                move->counts[str.substr(i+1)] += count;
            }            
        }
        move->end = true;
    }
    
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i=0; i<times.size(); ++i) {
            add(sentences[i], times[i]);
        }
        move = &head;
    }
    
    vector<string> input(char c) {
        if (c=='#') {
            add(search);
            search = "";
            move = &head;
            return vector<string>();
        }
        
        move = next(move, c);
        search += c;
        
        for (const auto& kv : move->counts) {
            pq.push(make_pair(kv.first, kv.second));
            if (pq.size()>3) {
                pq.pop();
            }
        }
        
        vector<string> res;
        while (!pq.empty()) {
            res.insert(res.begin(), search + pq.top().first);
            pq.pop();
        }
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */