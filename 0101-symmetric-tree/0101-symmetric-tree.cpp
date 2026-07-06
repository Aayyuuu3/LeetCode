class Solution {
public:
    bool helper(TreeNode *a, TreeNode *b){
        if(a==NULL && b==NULL) return true;
        else if((a==NULL && b!=NULL) || (a!=NULL && b==NULL)) 
            return false;
        return (a->val==b->val) &&
            helper(a->left,b->right) &&
            helper(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }
};