class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for(auto str:tokens) {
        	if(str.length()>1 || (str[0]<='9' && str[0]>='0')) {
        		num.push(atoi(str.c_str()));
        		continue;
        	}
        	int a=num.top(); num.pop();
        	int b=num.top(); num.pop();
        	int k;
        	switch(str[0]) {
        	case '+': k=a+b; break;
        	case '-': k=b-a; break;
        	case '*': k=a*b; break;
        	case '/': k=b/a; break;
        	}
        	num.push(k);
        }
        return num.top();
    }
};