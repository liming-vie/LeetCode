class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        stringstream ss;
        for (const auto & str : strs) {
            ss << str.length() << ' ';
            ss << str;
        }
        return ss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int idx, i=0;
        while (i<s.length()) {
            idx=s.find(' ', i);
            int l=atoi(s.substr(i, idx-i).c_str());
            res.push_back(s.substr(idx+1, l));
            i=idx+1+l;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));