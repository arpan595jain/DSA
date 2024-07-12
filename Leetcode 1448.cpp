class Solution {

    public:

    void solve(TreeNode * node,int cpm, int &ans){
        if(!node){return;}
        if(node->val>=cpm){++ans;cpm=node->val;}
        solve(node->left,cpm,ans);
        solve(node->right,cpm,ans);
    }

    int goodNodes(TreeNode* root) {
        int m=root->val;
        int ans = 0;
        solve(root,root->val,ans);
        return ans;
    }
};
