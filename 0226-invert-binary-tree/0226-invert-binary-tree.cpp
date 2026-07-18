class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->right);
        invertTree(root->left);
        return root;
    }
};