/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    inline TreeLinkNode *find (TreeLinkNode* root) {
        while (root) {
            if (root->left || root->right)  return root;
            root=root->next;
        }
        return NULL;
    }

    void connect(TreeLinkNode *root) {
        TreeLinkNode *prev = root, *cur, *next = NULL;

        while (prev) {
            cur = prev;
            while (cur) {
                TreeLinkNode* tmp=find(cur->next);
                if (cur->left) {
                    if (!next)  next=cur->left;
                    if (cur->right)  cur->left->next = cur->right;
                    else if (tmp) {
                        cur->left->next = tmp->left ? tmp->left : tmp->right;
                    }
                }
                if (cur->right) {
                    if (!next) next=cur->right;
                    if (tmp)   cur->right->next = tmp->left ? tmp->left : tmp->right;
                }
                cur=tmp;
            }
            prev = next;
            next = NULL;
        }
    }
};