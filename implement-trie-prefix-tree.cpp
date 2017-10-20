class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : end(false) {
        for(int i=0; i<26; ++i)
            next[i] = NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* move = this;
        for (char c : word) {
            c -= 'a';
            if (!move->next[c]) move->next[c] = new Trie();
            move = move->next[c];
        }
        move->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* move = this;
        for (char c : word) {
            c -= 'a';
            if (!move->next[c])
                return false;
            move = move->next[c];
        }
        return move->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* move = this;
        for (char c : prefix) {
            c -= 'a';
            if (!move->next[c])
                return false;
            move = move->next[c];
        }
        return true;
    }
    
private:
    bool end;
    Trie *next[26];
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */