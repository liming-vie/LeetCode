class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        if (!n) return 0;
        
        vector<int> vec(n, 0);
        int idx=0;
        for (const auto& word:words) {
            int k=0;
            for (char c:word) {
                k|=(1<<(c-'a'));
            }
            vec[idx++]=k;
        }
        
        int res=0;
        for (int i=0; i<n; ++i)
            for (int j=i+1; j<n; ++j) {
                if (vec[i]&vec[j])
                    continue;
                res = max(res, (int)words[i].length()*(int)words[j].length());
            }
        return res;
    }
};