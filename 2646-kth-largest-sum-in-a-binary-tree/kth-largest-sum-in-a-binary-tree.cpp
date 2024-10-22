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
    long long kthLargestLevelSum(TreeNode* root, int k) {
         queue<TreeNode*>q;
         q.push(root);
         vector<long long>sums;
        
         
         int nodes=1;
        while(!q.empty()){
            //we can calculate times
            int times=q.size();
            long long sum=0;
            for(int i=0;i<times;i++){
                TreeNode*temp=q.front();
                q.pop();
                sum=sum+temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }

            }
            sums.push_back(sum);
        }
       
        sort(sums.begin(),sums.end());
        if(k>sums.size()){
            return -1;
        }
        return sums[sums.size()-k];
       
    }
};