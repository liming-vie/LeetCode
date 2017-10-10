class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        mp[val].insert(nums.size());
        nums.push_back(val);
        return mp[val].size()==1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (mp[val].size() == 0)    return false;
        
        int idx = *mp[val].begin();
        mp[val].erase(idx);
        
        int n=nums.size();
        if (idx < n-1) {
            int v = nums[n-1];
            nums[idx] = v;
            
            mp[v].erase(n-1);
            mp[v].insert(idx);
            
        }
        nums.resize(n-1);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    
    unordered_map<int, unordered_set<int>> mp;
    vector<int> nums;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */