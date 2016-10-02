class Solution {
public:
    inline int count(int num) {
        int k=0x80;
        int n=0;
        while(k && (num & k)) {
            ++n;
            k>>=1;
        }
        return n;
    }
    bool validUtf8(vector<int>& data) {
        int bytes=data.size();
        if(!bytes)  return true;
        
        int n=0, cur;
        bool first = true;
        for(int i=0; i<bytes; ++i) {
            cur=count(data[i]);
            if(first) {
                n=cur - 1;
                if(n==0 || n==7) return false;
                if(n > 0) first = false;
                else n=0;
            }
            else {
                if(cur != 1)    return false;
                if(--n == 0) first = true;
            }
        }
        return n==0;
    }
};