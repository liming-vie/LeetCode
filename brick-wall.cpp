class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> sums;
        int sum=0;
        for (const auto& row : wall) {
            sum=0;
            for (int w : row) {
                sum += w;
                ++sums[sum];
            }
        }
        
        sums.erase(sums.find(sum));
        
        int maxs=0;
        for (const auto& kv : sums) {
            maxs = max(maxs, kv.second);
        }
            
        return wall.size() - maxs;
    }
};