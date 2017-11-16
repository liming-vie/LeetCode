class Solution {
public:
    bool equal(char a, char b) {
        if (a>b) swap(a,b);
        return a=='6'&&b=='9' || (a=='8'&&b=='8') || (a=='1'&&b=='1') || (a=='0'&&b=='0');
    }
    
    bool same(char c) {
        return c=='0' || c=='8' || c=='1';
    }
    
    bool isStrobogrammatic(string num) {
        int i=0, j=num.length()-1;
        while (i<j) {
            if (!equal(num[i++], num[j--]))
                return false;
        }
        if (i==j)   return same(num[i]);
        return true;
    }
};