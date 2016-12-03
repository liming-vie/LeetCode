class Solution {
public:
    string simplifyPath(string path) {
        path+='/';
        stack<string> st;
        int len=path.length();
        string name="";
        for(int i=0; i<len; ++i){
            if(path[i]!='/'){
                name+=path[i];
                continue;
            }
            if(name==".."){
                if(!st.empty())
                    st.pop();
            }else if(name!="." && name !=""){
                st.push(name);
            }
            name="";
        }
        string res="";
        while(!st.empty()){
            name=st.top();
            st.pop();
            res="/"+name+res;
        }
        return res==""?"/":res;
    }
};