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

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root && val==root->val){
            return root;
        }
       else if(root && val<root->val){
           
            //call for left
           return searchBST(root->left,val);
        }
       else if(root && val>root->val){
            //call for right
          return  searchBST(root->right,val);
        }
        return NULL;
    }
};