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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*,int>> st;
        int rootVal=0;
        int i=0;
        while(i<traversal.size()&&traversal[i]!='-'){
            rootVal=rootVal*10+traversal[i]-'0';
            i++;
        }
        TreeNode* root= new TreeNode(rootVal);
        st.push({root,0});

         
        while(i<traversal.size()){
            int depth=0;
            //calc depth
            while(i<traversal.size()&&traversal[i]=='-'){
                depth++;
                i++;
            }
            //calculate value of node
            int value=0;
            while(i<traversal.size()&&isdigit(traversal[i])){
                value=value*10+(traversal[i]-'0');
                i++;
            }
            //we have value and depth 
            while(!st.empty()&&st.top().second>=depth){
                st.pop();
                
            }
        
                
                TreeNode* parent=st.top().first;
                 TreeNode* newNode=new TreeNode(value);
                if(!parent->left){
                    
                    parent->left=newNode;
                }
                else{
                    parent->right=newNode;
                }
               
                st.push({newNode,depth});
            
        }


        return root;
        
    }
};