class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxLeft=maxDepth(root->left);
        int maxright=maxDepth(root->right);
        return max(maxLeft,maxright)+1;
        
    }
};
