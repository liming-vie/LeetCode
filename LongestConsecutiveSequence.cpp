class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(auto i:nums)    mp[i]=true;
        int res=0;
        for(auto i:mp) {
            if(!i.second)  continue;
            mp[i.first]=false;
            int cur=i.first+1;
            while(mp.find(cur)!=mp.end()) {
                mp[cur]=false;
                cur+=1;
            }
            int tmp=cur-i.first;
            res=res>tmp?res:tmp;
        }
        return res;
    }
};