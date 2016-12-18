/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* build(ListNode* head, int size) {
        if(!size)   return NULL;
        int t=size>>1;
        ListNode*move=head;
        while(t--) {
            move=move->next;
        }
        auto root=new TreeNode(move->val);
        t=size>>1;
        root->left=build(head, t);
        root->right=build(move->next, size-t-1);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* move=head;
        int size=0;
        while(move) {
            ++size;
            move=move->next;
        }
        return build(head, size);
    }
};