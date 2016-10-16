class Solution {
public:
    int min(int a,int b){
        if(a<b) return a;
        return b;
    }
    int maxArea(vector<int> &height) {
        int l=0,r=height.size()-1;
        int res=0;
        while(l<r){
            if(res<(r-l)*min(height[l],height[r]))  res=(r-l)*min(height[l],height[r]);
            if(height[l]<height[r]) ++l;
            else --r;
        }
        return res;
    }
};