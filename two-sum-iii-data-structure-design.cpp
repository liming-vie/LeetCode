class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++mp[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (const auto &kv : mp) {
            if (value == (kv.first<<1)) {
                if (kv.second > 1)  return true;
            } else if (mp.find(value-kv.first)!=mp.end())
                return true;
        }
        return false;
    }
    
private:    
    unordered_map<int, int> mp;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */