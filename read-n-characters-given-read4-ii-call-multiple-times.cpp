// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int copy(char* buf, int n) {
        int res;
        if (n >= left_) {
            memcpy(buf, buf4_, left_);
            res = left_;
            left_ = 0;
        } else {
            memcpy(buf, buf4_, n);
            for(int i=0; i<left_-n; ++i) {
                buf4_[i] = buf4_[i+n];
            }
            left_ -= n;
            res = n;
        }
        return res;
    }
    
    int read(char *buf, int n) {
        int count = copy(buf, n);
        buf += count;
        n -= count;
        
        while (n >= 4) {
            int tmp = read4(buf);
            count += tmp;
            if (tmp == 0) {
                return count;
            }
            n -= tmp;
            buf += tmp;
        }
        
        if (n && !left_) {
            left_ = read4(buf4_);
            count += copy(buf, n);
        }
        
        return count;
    }
private:
    char buf4_[4];
    int left_ = 0;
};