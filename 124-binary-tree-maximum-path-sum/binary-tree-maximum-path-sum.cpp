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
    int solve( TreeNode* node, int& maxi ){
        if( node == nullptr ){
            return 0;
        }
        int lsum = solve( node->left, maxi );
        lsum = max( 0, lsum );

        int rsum = solve( node->right, maxi );
        rsum = max( 0, rsum );

        maxi = max( lsum + rsum + node->val, maxi );
        return max( lsum, rsum ) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int ans = solve( root, maxi );
        return maxi;
    }
};