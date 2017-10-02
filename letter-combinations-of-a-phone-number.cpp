class Solution {
public:
    char letter[10][4] = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},
                            {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    
    vector<string> res;
    
    void func(const string& digits, int vi, const string str) {
        if (vi == digits.length()) {
            res.push_back(str);
            return;
        }
        for(const auto&c : letter[digits[vi]-'0']) {
            if (c=='\0')  break;
            func(digits, vi+1, str+c);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits == "") return res;
        
        func(digits, 0, "");
        return res;
    }
};