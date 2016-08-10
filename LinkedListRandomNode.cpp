class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head): move(head) {
        ListNode* m = head;
        length = 1;
        while(m->next) {
            m = m->next;
            ++length;
        }
        m->next = head;
        srand(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int k=rand() % length;
        while(k--) {
            move=move->next;
        }
        return move->val;
    }
    
private:
    ListNode* move;
    int length;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */