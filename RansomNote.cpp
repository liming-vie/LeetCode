class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;
        for(int i=0; i<magazine.length(); ++i) {
            mp[magazine[i]] += 1;
        }
        for(int i=0; i<ransomNote.length(); ++i) {
            mp[ransomNote[i]] -= 1;
            if(mp[ransomNote[i]] < 0) {
                return false;
            }
        }
        return true;
    }
};