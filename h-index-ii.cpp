class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l=0, r=n-1, mid, h;
        int res=0;
        while (l<=r) {
            mid = l+((r-l)>>1);
            h=n-mid;
            if (citations[mid]>=h) {
                r=mid-1;
                res=h;
            }
            else  l=mid+1;
        }
        return res;
    }
};