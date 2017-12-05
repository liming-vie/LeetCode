class Solution {
public:
    vector<string> res;
    
    void func(const string& word, const string& cur, int vi, bool pre) {
        if (vi==word.length()) {
            res.push_back(cur);
            return;
        }
        
        if (!pre) {
            for (int i=vi; i<word.length(); ++i) {
                func(word, cur+to_string(i-vi+1), i+1, true);
            }
        }
        func(word, cur+word[vi], vi+1, false);
    }
    
    vector<string> generateAbbreviations(string word) {
        string emp;
        func(word, emp, 0, false);
        return res;
    }
};