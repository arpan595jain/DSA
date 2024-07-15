class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr||p==root||q==root){
            return root;
        }
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);

    if(l==nullptr){
        return r;
    }
    else if(r==nullptr){
        return l;
    }
    else{
        return root;
    }
}
};
