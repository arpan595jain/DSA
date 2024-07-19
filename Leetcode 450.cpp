class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return root;
        }
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            TreeNode* rl = root->left; // rl = root left
            TreeNode* rr = root->right;// rr = root right
            if (!rl && !rr) {
                delete root;
                return nullptr;
            }
            if (!rl && rr) {
                // NECESSARY, otherwise delete will cause segfault
                root->right = nullptr;
                delete root;
                return rr;
            }
            if (!rr && rl) {
                // NECESSARY, otherwise delete will cause segfault
                root->left = nullptr;
                delete root;
                return rl;
            }
            else {
                TreeNode* temp = rr;
                TreeNode* parent = nullptr;
                while (temp->left) {
                    parent = temp;
                    temp = temp->left;
                }
                // clean up dangling pointers
                root->left = nullptr;
                root->right = nullptr;
                // INVARIANT: Temp has no left child
                temp->left = rl;
                if (parent){
                    parent->left = temp->right;
                    temp->right = rr;
                }
                return temp;
                delete root;
            } 
        }
        return root;
    }
};
