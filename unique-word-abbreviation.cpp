class ValidWordAbbr {
public:
    inline string abbr(const string& str) {
        if (str.length()<=2)    return str;
        else    return (str[0] + to_string(str.length()-2) + str[str.length()-1]);
    }
    
    ValidWordAbbr(vector<string> dictionary) {
        for (const string& str : dictionary) {
            mp[abbr(str)].insert(str);
        }
    }
    
    bool isUnique(string word) {
        const auto &ab=abbr(word);
        return mp[ab].count(word) == mp[ab].size();
    }
private:    
    unordered_map<string, unordered_set<string>> mp;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */