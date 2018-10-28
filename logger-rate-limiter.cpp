class Logger {
public:
    struct Trie {
        int timestamp = -1;
        unordered_map<char, Trie*> next;
    } root;
    
    /** Initialize your data structure here. */
    Logger() {
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        bool flag = true;
        Trie *move = &root;
        for (char c:message) {
            if (move->next.find(c) == move->next.end()) {
                move->next[c] = new Trie();
                flag = false;
            }
            move = move->next[c];
        }
        if (flag && timestamp - move->timestamp < 10) {
            return false;
        }
        move->timestamp = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */