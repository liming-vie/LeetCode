class LRUCache {
    struct List {
        List(int k, int v) : key(k), val(v) {}
        int key = -1;
        int val = -1;
        List *next = NULL;
        List *prev = NULL;
    };
    
public:
    LRUCache(int capacity) : capacity(capacity) { }
    
    void use(List* cur) {
        if (cur==head) {
            return;
        }
        
        if (cur == tail) {
            tail = tail->prev;
        } else if (cur->next) {
            cur->next->prev = cur->prev;
        }
        
        if (cur->prev) {
            cur->prev->next = cur->next;
            cur->prev = NULL;
        }
        
        if (head && head!=cur) {
            head->prev = cur;
            cur->next = head;
        }
        head = cur;
        
        if (!tail) {
            tail = cur;
        }
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            use(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        List *cur = NULL;
        if (mp.find(key) != mp.end()) {
            mp[key]->val = value;
            use(mp[key]);
            return;
        } else if (mp.size() == capacity) {
            mp.erase(tail->key);
            cur = tail;
            cur->key = key;
            cur->val = value;
        } else {
            cur = new List(key, value);
        }
        
        mp[key] = cur;
        use(cur);
    }
    
private:
    int capacity;
    List *head = NULL;
    List *tail = NULL;
    unordered_map<int, List*> mp;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */