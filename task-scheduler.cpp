class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count; // task, total count
        for (const auto&c : tasks) {
            ++count[c];
        }
        
        int mxcount = 0, mxnum = 0;
        for (const auto&iter: count) {
            if (mxcount == iter.second) {
                ++mxnum;
            } else if (mxcount < iter.second) {
                mxcount = iter.second;
                mxnum = 1;
            }
        }
        
        int partcount = mxcount - 1;
        int partlen = n - mxnum + 1;
        int left = tasks.size() - mxnum * mxcount;
        int idle = max(0, partlen * partcount - left);
        return tasks.size() + idle;
    }
};