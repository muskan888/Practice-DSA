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
    void solveRec(TreeNode*root){
        if(root==NULL){
            return;
        }
      
        TreeNode*temp=root->left;
        root->left=root->right;
        root->right=temp;
       
       solveRec(root->left);
        solveRec(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        solveRec(root);
        return root;
    }
};