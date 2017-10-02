class Solution {
public:
    #define ORD(a) (int)((a)-'0')
    #define CHAR(a) (char)((a)+'0')
    #define PROCESS(a)  \
        y=a>>1;         \
        a=CHAR(a&1);    
        
    string addBinary(string a, string b) {
        int la=a.length()-1, lb=b.length()-1;

        int y=0;
        while(la>=0 && lb>=0) {
            a[la]=ORD(a[la])+ORD(b[lb])+y;
            PROCESS(a[la]);
            --la,--lb;
        }
        while(la>=0) {
            a[la]=ORD(a[la])+y;
            PROCESS(a[la]);
            --la;
        }
        while(lb>=0) {
            a=char(ORD(b[lb])+y)+a;
            PROCESS(a[0]);
            --lb;
        }
        if(y)   a='1'+a;
        // remove leading zero
        int i=0;
        la=a.length()-1;
        while(i<la && a[i]=='0')    ++i;
        return a.substr(i);
    }
};