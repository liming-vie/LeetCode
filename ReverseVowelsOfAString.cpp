#define TOLOWER(c) if (c>='A' && c<='Z')    c=c-'A'+'a'; 
#define IS(c)  (c=='a' || c=='e' || c=='o' || c=='i' || c=='u')

class Solution {
public:
    string reverseVowels(string s) {
        int l=0, r=s.length()-1;
        while(l<r) {
            char cl = s[l];
            TOLOWER(cl);
            char cr = s[r];
            TOLOWER(cr);
            if(!IS(cl)) 
                ++l;
            else if (!IS(cr)) 
                --r;
            else {
                swap(s[l], s[r]);
                ++l;
                --r;
            }
        }
        return s;
    }
};