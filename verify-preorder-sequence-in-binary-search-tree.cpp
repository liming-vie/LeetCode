class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
	    int low=1<<31, i=-1;
        for (int p : preorder) {
            if (p < low) return false;
            while (i>=0 && preorder[i] < p) {
                low = preorder[i--];
            }
            preorder[++i] = p;
        }
        return true;
    }
};