class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> st;
        int p,pre=0;
        int n = 0;
        while(true) {
            p=preorder.find(',',pre);
            string str = preorder.substr(pre, p-pre);
            st.push_back(str);
            ++n;
            while(st.size() > 2 && st[n-1] == "#" && st[n-2] == "#" && st[n-3] != "#") {
                st.resize(n-3);
                st.push_back(str);
                n-=2;
            }
            if(p==-1) break;
            pre=p+1;
        }
        return n == 1 && st[0] == "#";
    }
};