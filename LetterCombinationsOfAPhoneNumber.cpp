class Solution {
public:
    vector<vector<char>> letter { {}, {} , {'a','b','c'},
        {'d','e','f'}, {'g','h','i'}, {'j','k','l'}, 
        {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};
        
    vector<string> res;
    
    void proc(string& digits, int vi, string cur) {
        if (vi == digits.length())  {
            res.push_back(cur);
            return;
        }
        int num = digits[vi]-'0';
        for(int i=0; i<letter[num].size(); ++i) {
            proc(digits, vi+1, cur+letter[num][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)  return res;
        res.clear();
        proc(digits, 0, "");
        return res;
    }
};