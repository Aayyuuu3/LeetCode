class Solution {
public:

    int height(TreeNode *n){
        if(n == NULL)
            return -1;
        return max(height(n->right), height(n->left)) + 1;
    }

    int getBF(TreeNode *n){
        if(n == NULL)
            return 0;
        return height(n->right) - height(n->left);
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if(abs(getBF(root)) > 1)
            return false;
        return isBalanced(root->left) && 
            isBalanced(root->right);
    }
};