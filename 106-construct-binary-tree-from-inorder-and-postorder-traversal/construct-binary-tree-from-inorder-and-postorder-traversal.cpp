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
    int findpos(int element, unordered_map<int,int>&mp){
        return mp[element];
    }
    TreeNode* buildTreeRec(vector<int>& inorder, vector<int>& postorder, int&postIndex, int InStartIndex, int InEndIndex,unordered_map<int,int>&mp){
        if(postIndex<0|| InStartIndex>InEndIndex){
            return NULL;
        }
        //create root
        int element=postorder[postIndex];
        postIndex--;
        TreeNode* newNode= new TreeNode(element);
        //find element in inorder
        int pos=findpos(element,mp);

        //first right call then left call because post order is given (LRN->LEFT , RIGHT, ROOT)
        //We are going from right to left
        newNode->right=buildTreeRec(inorder,postorder,postIndex,pos+1,InEndIndex,mp);
         newNode->left=buildTreeRec(inorder,postorder,postIndex,InStartIndex,pos-1,mp);
         return newNode;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int postIndex=postorder.size()-1;
        return buildTreeRec(inorder,postorder,postIndex,0,inorder.size()-1,mp);
    }
};