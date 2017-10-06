class WordDictionary {
public:
    struct Trie {
        Trie () : end(false) {
            for (int i=0; i<26; ++i) {
                next[i] = NULL;
            }
        }
        bool end;
        Trie* next[26];
    };
    
    Trie trie;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie *move = &trie;
        
        for (int i=0; i<word.length(); ++i) {
            int c = word[i] - 'a';
            if (!move->next[c]) {
                move->next[c] = new Trie();
            }
            move = move->next[c];
        }
        
        move->end = true;
    }
    
    bool func(const string& word, Trie *move, int vi) {
        for (int i=vi; word[i]; ++i) {
            if (word[i] != '.') {
                if (move->next[word[i] - 'a']) {
                    move = move->next[word[i] - 'a'];
                } else {
                    return false;
                }
            } else {
                for (int j=0; j<26; ++j) {
                    if (move->next[j]) {
                        if (func(word, move->next[j], i+1)) {
                            return true;
                        }
                    }
                }
                return false;
            }
        }
        return move->end;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return func(word, &trie, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */ 