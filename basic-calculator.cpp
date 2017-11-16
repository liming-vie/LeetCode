class Solution {
public:
    int compute(int a, int b, char sign) {
        return sign=='-'?(a-b):(a+b);
    }
    
    int calculate(string s) {
        stack<pair<int, char>> st;
        char sign='+';
        int res=0;
        int cur=0;
        for (char c : s) {
            switch (c) {
                case ' ':
                    break;
                case '(':
                    st.push(make_pair(res, sign));
                    cur=res=sign=0;
                    break;
                case ')':
                    res = compute(res, cur, sign);
                    res = compute(st.top().first, res, st.top().second);
                    st.pop();
                    sign=cur=0;
                    break;
                case '+':
                case '-':
                    res = compute(res, cur, sign);
                    sign=c;
                    cur=0;
                    break;
                default:
                    cur*=10;
                    cur+=(c-'0');
            }
        }
        res = compute(res, cur, sign);
        return res;
    }
};