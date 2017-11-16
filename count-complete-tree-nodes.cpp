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
    inline int height(TreeNode* root) {
        int h=0;
        while (root->left) {
            root = root->left;
            ++h;
        }
        return h;
    }
    
    bool find(TreeNode* root, int left, int right, int target) {
        if (!root)   return false;
        if (target == right && left == target)    return true;
        
        int mid = left + ((right-left)>>1);
        if (target <= mid) return find(root->left, left, mid, target);
        return find(root->right, mid+1, right, target);
    }
    
    int countNodes(TreeNode* root) {
        if (!root)  return 0;
        
        int h=height(root);
        int left=0, right=(1<<h)-1;
        int l=left, r=right;
        while (l<=r) {
            int mid = l+((r-l)>>1);
            if (find(root, left, right, mid)) 
                l=mid+1;   
            else r=mid-1;
        }
        return l + (1<<h) - 1;
    }
};