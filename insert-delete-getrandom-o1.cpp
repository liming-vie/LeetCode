class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand((unsigned)time(NULL)); 
        vals_.reserve(100);
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (index_.find(val) != index_.end()) {
            return false;
        }
        index_[val] = vals_.size();
        vals_.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (index_.find(val) == index_.end()) {
            return false;
        }
        int n=vals_.size() - 1;
        int last = vals_[n];
        int idx = index_[val];
        vals_[idx] = last;
        index_[last] = idx;
        index_.erase(val);
        vals_.resize(n);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vals_[rand() % vals_.size()];
    }
    
private:
    vector<int> vals_;
    map<int,int> index_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */