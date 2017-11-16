class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val, count=0;
        for(int n:nums) {
            if (count==0)  {
                count=1;
                val=n;
            } else if (n==val) ++count;
            else --count;
        }
        return val;
    }
};