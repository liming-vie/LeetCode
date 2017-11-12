class Solution {
public:
    struct Trie {
        Trie () : end(false) {
            for (int i=0; i<26; ++i)
                next[i] = NULL;
        }
        
        bool end;
        Trie* next[26];
    } trie;
    
    vector<string> res;
    
    void build(const string& word) {
        Trie* root = &trie;
        for (char c : word) {
            c-='a';
            if (root->next[c]==NULL) {
                root->next[c] = new Trie();
            }
            root = root->next[c];
        }
        root->end = true;
    }
    
    int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void search(vector<vector<char>>& board, int vi, int vj, Trie* root, string str) {
        if (vi<0 || vi==board.size() || vj<0 || vj==board[0].size() || !board[vi][vj] || !root->next[board[vi][vj]-'a'])
            return;
        
        char c = board[vi][vj];
        str.push_back(c);
        board[vi][vj]=0;
        
        if (root->next[c-'a']->end)   {
            res.push_back(str);
            root->next[c-'a']->end=false;
        }
        root = root->next[c-'a'];
        
        for (int i=0; i<4; ++i) {
            search(board, vi+d[i][0], vj+d[i][1], root, str);
        }
        
        board[vi][vj]=c;
        str.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const auto& word : words) {
            build(word);
        }
        
        for (int i=0; i<board.size(); ++i)
            for (int j=0; j<board[0].size(); ++j)
                search(board, i, j, &trie, "");
        
        return res;
    }
};