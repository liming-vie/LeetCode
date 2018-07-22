/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int res=0;
    
    int helper(TreeNode* root, int* max, int* min) {
        *max = *min = root->val;
        int count = 1;
        bool flag=true;
        if (root->left) {
            int lmax, lmin, lc;
            if ((lc = helper(root->left, &lmax, &lmin)) && lmax < root->val) {
                *min = lmin;
                count += lc;
            } else flag=false;
        }
        if (root->right) {
            int rmax, rmin, rc;
            if ((rc = helper(root->right, &rmax, &rmin)) && rmin > root->val) {
                *max = rmax;
                count += rc;
            } else flag=false;
        }
        if (!flag)  return 0;
        res = count > res ? count : res;
        return count;
    }
    
    int largestBSTSubtree(TreeNode* root) {
        if (!root)  return 0;
        int max, min;
        helper(root, &max, &min);
        return res;
    }
};
