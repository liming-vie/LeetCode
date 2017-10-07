class Solution {
public:
    unsigned long long getTime(const string& str) {
        unsigned long long res = 0;
        for(char c : str) {
            res *= 10;
            res += (c-'0');
        }
        return res;
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        
        stack<int> st;
        
        unsigned long long timestep, lasttime;
        
        int curId = -1;
        for (const string& log : logs) {
            int v1 = log.find(':');
            int id = atoi(log.substr(0, v1).c_str());
            
            int v2 = log.find(':', v1+1);
            bool start = ((v2-v1-1) == 5);
            
            timestep = getTime(log.substr(v2+1));
            if (curId >= 0) {
                res[curId] += timestep - lasttime - 1;
            }
            ++res[id];
            
            if (start) {
                st.push(curId);
                curId = id;
            } else {
                curId = st.top();
                st.pop();
            }
            
            lasttime = timestep;
        }
        
        return res;
    }
};