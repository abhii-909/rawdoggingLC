/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int m = 0;
    int ddf(TreeNode* root){
        if(root == NULL) return 0;
        int l = ddf(root->left);
        int r = ddf(root->right);
        m = max(m, l+r);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ddf(root);
        return m;
    }
};