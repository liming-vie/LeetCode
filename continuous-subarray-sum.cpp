class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size()<2) return false;
        long long t = k;
        t=t<0?-t:t;
        
        int sum=0, tmp;
        unordered_map<int, int> mod, sums;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if (i && (!sum || sum==t))    return true;            
            
            if (t) {
                tmp = sum % t;
                
                if (i && tmp == 0)   return true;
                
                if ((mod.find(tmp)!=mod.end() && mod[tmp]<i-1) || 
                    (mod.find(t-tmp)!=mod.end() && mod[t-tmp]<i-1))
                    return true;
                
                if (mod.find(tmp) == mod.end()) mod[tmp] = i;
            }
            
            if (sums.find(sum) == sums.end())   sums[sum] = i;
            else if (sums[sum] < i-1)   return true;
        }
        
        return sums.find(sum)!=sums.end() && sums[sum]<nums.size()-2;
    }
};