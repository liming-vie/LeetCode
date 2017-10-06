class Solution {
public:
    vector<string> res;
    
    void search(const string&num, const string& str, int target, int vi, long long diff, long long sum) {
        if (vi == num.length()) {
            if (sum == target) { 
                res.push_back(str);
            }
            return;
        }
        
        long long cur = 0;
        for (int i=vi; i<num.length(); ++i) {
            if (i != vi && num[vi] == '0')    break;
            
            cur *= 10;
            cur += num[i]-'0';
            const string &curn = num.substr(vi, i-vi+1);
            
            if (str.length()) {
                search(num, str+'+'+curn, target, i+1, cur, sum+cur);
                search(num, str+'-'+curn, target, i+1, -cur, sum-cur);
                int tmp=diff*cur;
                search(num, str+'*'+curn, target, i+1, tmp, (sum-diff)+tmp);
            } else {
                search(num, curn, target, i+1, cur, cur);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        search(num, "", target, 0, 0, 0);
        return res;
    }
};