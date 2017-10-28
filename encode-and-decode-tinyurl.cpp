class Solution {
public:
    unordered_map<string, string> l2s;
    unordered_map<string, string> s2l;
    
    const string dict="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string prefix="http://tinyurl.com/";
    
    string concat(const string& str) {
        return prefix+str;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (l2s.find(longUrl) != l2s.end()) {
            return concat(l2s[longUrl]);
        }
        
        string str="";
        do {
            str += dict[rand()%62];
        } while (s2l.find(str)!=s2l.end());
        
        l2s[longUrl]=str;
        s2l[str]=longUrl;
        
        return concat(str);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return s2l[shortUrl.substr(prefix.length())];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));