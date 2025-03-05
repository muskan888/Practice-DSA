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
    void createBST(int data,TreeNode*root){
        if(!root){
            return;
        }
        TreeNode *node= new TreeNode(data);
        if(node->val>root->val){
            if(root->right==NULL){
                root->right=node;
              
            }
            else{
                createBST(data,root->right);
            }
        }
        if(node->val<root->val){
            if(root->left==NULL){
                root->left=node;
                 
            }
            else{
               
                createBST(data,root->left);
            }
        }

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root= new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            createBST(preorder[i],root);
        }
        return root;
    }
};