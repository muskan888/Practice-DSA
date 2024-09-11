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
    bool flag=false;
 void pathSumRec(TreeNode* root, int targetSum, int currSum){
        if(!root){
            return;
        }
        currSum+=root->val;
        //check if we have got target sum and reached the leaf node
        if(currSum==targetSum && root->left==NULL && root->right==NULL){
            flag=true;
            return;
        }
        pathSumRec(root->left,targetSum,currSum);
        pathSumRec(root->right,targetSum,currSum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        pathSumRec(root,targetSum,0);
        return flag;
    }
};