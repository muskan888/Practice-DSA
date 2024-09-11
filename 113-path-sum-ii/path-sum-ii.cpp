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
vector<vector<int>> ans;
    void pathSumRec(TreeNode* root, int targetSum, int currSum,vector<int>path){
        if(!root){
            return;
        }
        currSum+=root->val;
        //check if we have got target sum and reached the leaf node
        if(currSum==targetSum && root->left==NULL && root->right==NULL){
            path.push_back(root->val);
            ans.push_back(path);
            return;
        }
        path.push_back(root->val);
        pathSumRec(root->left,targetSum,currSum,path);
        pathSumRec(root->right,targetSum,currSum,path);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        pathSumRec(root,targetSum,0,path);
        return ans;
    }
};