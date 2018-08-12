class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        for (int i=0; i<words.size(); ++i) {
            string rev=words[i];
            reverse(rev.begin(), rev.end());
            mp[rev] = i;
        }
        
        vector<vector<int>> res;
        if (mp.find("") != mp.end()) {
            for (int i=0; i<words.size(); ++i) {
                if (i!=mp[""] && isPalindrome(words[i])) {
                    res.push_back({mp[""], i});
                }
            }
        }
        
        for (int i=0; i<words.size(); ++i) {
            for (int l=0; l<words[i].length(); ++l) {
                string left = words[i].substr(0, l);
                string right = words[i].substr(l, words[i].length()-l);
                
                if (mp.find(right)!=mp.end() && isPalindrome(left) && mp[right]!=i) {
                    res.push_back({mp[right], i});
                }
                
                if (mp.find(left)!=mp.end() && isPalindrome(right) && mp[left]!=i) {
                    res.push_back({i, mp[left]});
                }
            }
        }
        return res;
    }
    
    bool isPalindrome(const string& str) {
        int i=0, j=str.length()-1;
        while (i<j) {
            if (str[i] != str[j]) return false;
            ++i, --j;
        }
        return true;
    }
};
