#define VALID(c) ((c<='z' && c>='a') || (c<='Z'&&c>='A') || (c<='9'&&c>='0'))
#define LOWERCASE(c) ((c<='Z'&&c>='A')?(c-'A'+'a'):c)
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0, r=s.length()-1;
        while(l<r) {
            if(!VALID(s[l]))    ++l;
            else if(!VALID(s[r]))   --r;
            else {
                if(LOWERCASE(s[l]) != LOWERCASE(s[r]))
                    return false;
                ++l;
                --r;
            }
        }
        return true;
    }
};