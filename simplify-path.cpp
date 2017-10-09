class Solution {
public:
    int end(string&path, int vi) {
        for(int i=vi+1; i<path.length(); ++i) 
            if(path[i]=='/')
                return i;
        return path.length();
    }
    string simplifyPath(string path) {
        stack<string> st;
        int len=path.length();
        for(int i=0; i<len; ++i) {
            if(path[i]=='/')    continue;
            
            int e=end(path,i);
            string cur=path.substr(i, e-i);
            i=e;
            if(cur=="..") {
                if(!st.empty())
                    st.pop();
            }
            else if(cur!=".") st.push(cur);
        }
        
        string res="";
        while(!st.empty()) {
            res="/"+st.top()+res;
            st.pop();
        }
        return res==""?"/":res;
    }
};