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
    unordered_map<int,int>postindex;
    TreeNode* construct(vector<int>&preorder, vector<int>&postorder,int prestart, int preend, int poststart, int postend){
        if(prestart>preend){
            return nullptr;
        }
         TreeNode* root=new TreeNode(preorder[prestart]);
        //only one node
        if(prestart==preend){
            return root;
        }
        int leftrootval=preorder[prestart+1];
        int leftrootidxinpost=postindex[leftrootval];
        //calculate size of left subtree
        int sizeofleftsubtree=leftrootidxinpost-poststart+1;

        //call for left

       root->left=construct(preorder,postorder,prestart+1,prestart+sizeofleftsubtree,poststart,leftrootidxinpost);

       //call for right
       root->right=construct(preorder,postorder,prestart+sizeofleftsubtree+1,preend,leftrootidxinpost+1,postend-1);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();i++){
            postindex[postorder[i]]=i;
        }
        int n=preorder.size();
        return construct(preorder,postorder,0,n-1,0,n-1);
    }
};