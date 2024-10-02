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
    vector<int> pre;
    void preOrder(TreeNode*node){
        if(!node){
            return;
        }
        pre.push_back(node->val);
        preOrder(node->left);
        preOrder(node->right);
    }
    void flatten(TreeNode* root) {
        preOrder(root);
        TreeNode*temp=root;
        for(int i=1;i<pre.size();i++){
        
           temp->right=new TreeNode(pre[i]);
           temp->left=nullptr;
           temp=temp->right;
        }
      
}
};