class Solution {
public:
    unordered_map<char, unordered_set<char>> next;
    unordered_map<char, int> degree;
    
    void AddWord(const string& word) {
        for (char c : word) {
            if (degree.find(c)==degree.end()) {
                degree[c] = 0;
            }
        }
    }
    
    void Diff(const string& a, const string& b) {
        int l1=a.length(), l2=b.length();
        int i=0, j=0;
        
        for (; i<l1 && j<l2; ++i, ++j) {
            if (a[i] == b[j])   continue;
            if (next[a[i]].find(b[j]) == next[a[i]].end()) {
                degree[b[j]] += 1;
                next[a[i]].insert(b[j]);
            }
            break;   
        }
    }
    
    string alienOrder(vector<string>& words) {
        int n=words.size();
        if (!n) return "";
        
        next.clear();
        degree.clear();
        
        AddWord(words[0]);
        for (int i=1; i<n; ++i) {
            AddWord(words[i]);            
            Diff(words[i-1], words[i]);
        }
        
        queue<char> q;
        for (const auto& kv : degree) {
            if (kv.second==0) {
                q.push(kv.first);
            }
        }
        
        string res;
        while (!q.empty()) {
            res += q.front();
            for (char c : next[q.front()]) {
                if ((--degree[c]) == 0) {
                    q.push(c);
                }
            }
            q.pop();
        }
        
        for (const auto& kv : degree) {
            if (kv.second > 0)  return "";
        }
        
        return res;
    }
};