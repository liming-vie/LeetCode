class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(NULL));
        vals.reserve(100);
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        mp[val].push_back(vals.size());
        vals.push_back(val);
        return mp[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(mp[val].size() == 0) {
            return false;
        }
        int idx = mp[val].back();
        mp[val].pop_back();
        
        int last=vals.size()-1;
        int tmp=vals[last];
        vals[idx]=tmp;
        vals.resize(last);
        for(auto i=mp[tmp].begin(); i!=mp[tmp].end(); ++i) {
            if(*i==last) {
                *i=idx;
                break;
            }
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vals[rand() % vals.size()];
    }
    
private:
    map<int, vector<int>> mp;
    vector<int> vals;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */