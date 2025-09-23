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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }

private:
    int dfs(TreeNode* root, int mx){
        if(root == NULL) return 0;
        
        int count = 0;

        //check if current node is good
        if(root->val >= mx){
            count = 1;
        }

        int newMax = max(mx, root->val);

        //left aur right me good nodes count karlete hai
        count += dfs(root->left, newMax);
        count += dfs(root->right, newMax);

        return count;
    }
};