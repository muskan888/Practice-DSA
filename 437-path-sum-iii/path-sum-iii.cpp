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
        int ways=0;
     void  findPaths(TreeNode*node, int target, long long curr){
           if(!node){
                return;
            }
            curr=curr+node->val;
            if(curr==target){
                ways++;
            }
            findPaths(node->left,target,curr);
            findPaths(node->right,target,curr);
        }
    void solveUsingRec(TreeNode*node, int target){
        if(!node){
            return;
        }
        findPaths(node,target,0);
        solveUsingRec(node->left,target);
        solveUsingRec(node->right,target);
    }
    int pathSum(TreeNode* root, int targetSum) {
        solveUsingRec(root,targetSum);
        return ways;
    }
};