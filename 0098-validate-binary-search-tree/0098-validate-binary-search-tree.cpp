class Solution {
public:
    bool helper(TreeNode *a, TreeNode *max, TreeNode *min){
        if(a==NULL) return true;
        if(max!=NULL && a->val>=max->val) return false;
        if(min!=NULL && a->val<=min->val) return false;
        return helper(a->left,a,min) &&
            helper(a->right,max,a);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL);
    }   
};