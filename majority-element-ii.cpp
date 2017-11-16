class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1, num2, c1=0, c2=0;
        for (int n:nums) {
            if ((c1==0 || num1==n) && (c2==0 || num2!=n)) {
                ++c1;
                num1=n;
            } else if (c2==0 || num2==n) {
                ++c2;
                num2=n;
            } else {
                --c1;
                --c2;
            }
        }
        
        c1=c2=0;
        for (int n:nums) {
            if (num1==n)    ++c1;
            else if (num2==n)   ++c2;
        }
        
        cout << num1 << "," << c1 << " " << num2 << "," << c2 << endl;
        
        vector<int> res;
        if (c1>(nums.size()/3))   res.push_back(num1);
        if (c2>(nums.size()/3))   res.push_back(num2);
        return res;
    }
};