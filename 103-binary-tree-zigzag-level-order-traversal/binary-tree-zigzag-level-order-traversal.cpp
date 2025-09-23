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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;

        q.push(root);
        int flag = 0;

        vector<vector<int>> ans;

        while(!q.empty()){
            int n = q.size();
            vector<int> temp(n);

            for(int i = 0; i < n; i++){
                int idx;
                if(flag % 2 == 0){
                    idx = i;                // left -> right
                }else{
                    idx = n - i - 1;        // right -> left
                }
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                temp[idx] = node->val;
            }
            ans.push_back(temp);
            flag++;
        }
        return ans;
    }
};