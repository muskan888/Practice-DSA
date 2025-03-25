class Solution {
public:
    // Helper to find max node in left subtree (inorder predecessor)
    TreeNode* inorderPre(TreeNode* root) {
        while (root && root->right) {
            root = root->right;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Node with one or no child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get inorder predecessor (max in left subtree)
            TreeNode* pred = inorderPre(root->left);
            root->val = pred->val;  // Copy value
            root->left = deleteNode(root->left, pred->val);  // Delete the inorder predecessor
        }

        return root;
    }
};
