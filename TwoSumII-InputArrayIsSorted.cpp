class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0, r=numbers.size()-1, sum;
        while(l<r) {
            sum=numbers[l]+numbers[r];
            if (sum<target) ++l;
            else if (sum>target) --r;
            else return vector<int>{l+1, r+1};
        }
    }
};