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
    stack<TreeNode*> s1, s2;

    void pushLeft(TreeNode* root) {
        while (root) {
            s1.push(root);
            root = root->left;
        }
    }

    void pushRight(TreeNode* root) {
        while (root) {
            s2.push(root);
            root = root->right;
        }
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        pushLeft(root);
        pushRight(root);

        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        while (!s1.empty() && !s2.empty() && s1.top() != s2.top()) {
            left = s1.top();
            right = s2.top();

            int sum = left->val + right->val;

            if (sum == k) return true;

            else if (sum < k) {
                // move left pointer forward
                s1.pop();
                pushLeft(left->right);
            } 
            else {
                // move right pointer back
                s2.pop();
                pushRight(right->left);
            }
        }

        return false;
    }
};