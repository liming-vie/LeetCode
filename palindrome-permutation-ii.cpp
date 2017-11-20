class Solution {
public:
    unordered_map<char, int> count;
    vector<string> res;
    
    void dps(string mid, int left, string str) {
        if (!left) {
            string t=str;
            reverse(t.begin(), t.end());
            res.push_back(str+mid+t);
            return ;
        }
        
        --left;
        for (auto &kv : count) {
            if (kv.second) {
                --kv.second;
                str.push_back(kv.first);
                dps(mid, left, str);
                str.pop_back();
                ++kv.second;
            }
        }
    }
    
    vector<string> generatePalindromes(string s) {
        for (char c:s) ++count[c];
        
        int sum=0;
        for (const auto &kv : count) {
            sum+=(kv.second&1);
        }
        if (sum>1)    return res;
        
        char mid=0;
        sum=0;
        for (auto &kv : count) {
            if (kv.second&1) {
                mid = kv.first;
            }
            kv.second >>= 1;
            sum += kv.second;
        }
        
        string tmp="";
        if (mid) tmp=mid;
        dps(tmp, sum, "");
        
        return res;
    }
};