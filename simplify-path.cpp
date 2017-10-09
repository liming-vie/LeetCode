class Solution {
public:
    void process(vector<string> &dirs, const string &str) {
        if (str == "..")    {
            if (dirs.size())    dirs.pop_back();
        } else if (str != "" && str != ".")  dirs.push_back(str);
    }
    
    string simplifyPath(string path) {
        vector<string> dirs;
        for (int i=1; i<path.length(); ) {
            int vi = path.find('/', i);
            if (vi == -1) {
                process(dirs, path.substr(i));
                i = path.length();
            } else {
                process(dirs, path.substr(i, vi-i));
                i = vi+1;
            }
        }
        
        if (dirs.empty())   return "/";
        
        stringstream ss;
        for (const string& str : dirs) {
            ss << '/' << str;
        }
        return ss.str();
    }
};