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
    int findPosition(vector<int>& inorder,int element){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildTreeRec(vector<int>& preorder, vector<int>& inorder,int&preIdx, int InStartIdx, int InEndIdx ){
        //BC
        if(preIdx>=preorder.size() || InStartIdx>InEndIdx){
            return NULL;
        }
        int element=preorder[preIdx];
        cout<<element<<endl;
        preIdx++;
        TreeNode* newNode= new TreeNode(element);

        //Find position of newnode in Inorder 
        int pos=findPosition(inorder,element);
        cout<<" pos"<<pos<< endl;

        //Solve for left and Right
        newNode->left=buildTreeRec(preorder,inorder,preIdx,InStartIdx,pos-1);
        newNode->right=buildTreeRec(preorder,inorder,preIdx,pos+1,InEndIdx);

        return newNode;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx=0;
        return buildTreeRec(preorder,inorder,preIdx,0,inorder.size()-1);
    }
};