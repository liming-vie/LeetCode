class LRUCache {
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node():prev(NULL),next(NULL){}
        Node(int k, int v):key(k), val(v), prev(NULL), next(NULL) {}
    };
    
public:
    LRUCache(int capacity) : capacity_(capacity) {
        head_=new Node();
        tail_=head_;
    }
    // insert the node in the first place
    void insert_first(Node* cur) {
        cur->prev=head_;
        cur->next=head_->next;
        if(cur->next)   cur->next->prev=cur;
        head_->next=cur;
        if(tail_==head_)    tail_=head_->next;
    }
    // use the node with key
    // move the node to the first place
    void use(int key) {
        auto cur=mp_[key];
        if(cur==tail_) {
            tail_=tail_->prev;
            tail_->next=NULL;
        } else {
            cur->prev->next=cur->next;
            if(cur->next)   cur->next->prev=cur->prev;
        }
        insert_first(cur);
    }
    
    int get(int key) {
        if (mp_.find(key)!=mp_.end()) {
            use(key);
            return mp_[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* cur;
        if (mp_.find(key) != mp_.end()) {
            mp_[key]->val=value;
            use(key);
            return;
        }
        else if (mp_.size() == capacity_) {
            mp_.erase(tail_->key);
            tail_->key=key;
            tail_->val=value;
            tail_->prev->next=NULL;
            cur=tail_;
            tail_=tail_->prev;
        }
        else    cur=new Node(key, value);
        
        insert_first(cur);
        
        mp_[key]=cur;
    }
    
private:
    int capacity_;
    Node *head_;
    Node *tail_;
    unordered_map<int, Node*> mp_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */