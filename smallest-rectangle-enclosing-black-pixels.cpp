class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int n=image.size();     if (!n) return 0;
        int m=image[0].size();  if (!m) return 0;
        
        int l=search(image, 0, y, 0, n-1, true, false);
        int r=search(image, y, m-1, 0, n-1, false, false);
        int u=search(image, 0, x, 0, m-1, true, true);
        int d=search(image, x, n-1, 0, m-1, false, true);
        return (r-l+1)*(d-u+1);
    }
    
    bool isWhite(const vector<vector<char>>& image, int mid, int x, bool row) {
        return (row ? image[mid][x] : image[x][mid]) == '0';
    }
    
    int search(const vector<vector<char>>& image, int i, int j, int low, int high, bool dir, bool row) {
        int mid, k;
        while (i <= j) {
            mid = i+((j-i)>>1);
            k=low;
            while (k<=high && isWhite(image, mid, k, row)) ++k;
            if ((k<=high)==dir) {
                j=mid-1;
            } else {
                i=mid+1;
            }
        }
        return dir ? i : j;
    }
};