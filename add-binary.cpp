class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) {
            swap(a, b);
        }
        int i=a.length()-1, j=b.length()-1;
        int y=0;
        while(j>=0) {
            a[i] = (a[i]-'0') + (b[j]-'0') + y;
            y=(a[i] > 1);
            a[i] = (a[i] & 1) + '0';
            --i, --j;
        }
        while (i>=0) {
            a[i] = (a[i]-'0') + y;
            y=(a[i] > 1);
            a[i] = (a[i] & 1) + '0';
            --i;
        }
        if (y) return '1' + a;
        return a;
    }
};