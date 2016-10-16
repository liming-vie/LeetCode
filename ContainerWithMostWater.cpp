class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int res=0;
        while(l<r) {
            int tmp=(r-l)*min(height[l],height[r]);
            res = res > tmp ? res : tmp;
            if(height[l] < height[r])   ++l;
            else    --r;
        }
        return res;
    }
};