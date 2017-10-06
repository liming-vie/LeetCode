// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int count = 0, cur=4;
        while (n>0 && cur==4) {
            cur = read4(buf);
            count += cur;
            buf += cur;
            n -= cur;
        }
        
        if (n) {
            char buf4[4];
            cur = read4(buf4);
            for (int i=0; i<n && i<cur; ++i) {
                buf[i] = buf4[i];
            }
            count += (cur > n ? n : cur);
        }
        
        return count;
    }
};