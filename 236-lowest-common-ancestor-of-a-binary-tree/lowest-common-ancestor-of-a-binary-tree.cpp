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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root==NULL ||root==p||root==q){
            return root;
        }
        //check whether any of p or q is on left or right 
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left==NULL){       //it means p and q both are in the right part of the tree
            return right;
        }
        else if(right==NULL){   //it means both are in the left part of the tree
            return left;
        }
        else{              //it means one is in the left part and other one is in the right part 
            return root;
        }

    }
};