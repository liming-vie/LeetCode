class Solution {
public:
#define mk(a,b) make_pair(a,b)
    bool isValid(string s) {
        map<char,char> mp;
        mp.insert(mk('}','{'));
        mp.insert(mk(']','['));
        mp.insert(mk(')','('));
        stack<char> st;
        for(auto i:s)
            switch(i) {
            case '(':
            case '[':
            case '{':
                st.push(i);
                break;
            case ')':
            case ']':
            case '}':
                if(st.size()==0 || st.top() != mp[i]) return false;
                st.pop();
            }
        return st.size() == 0;
    }
};