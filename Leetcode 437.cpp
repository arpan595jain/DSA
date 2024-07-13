class Solution {
    unordered_map<long long,long long> mp;
    int ans = 0;
public:
    void getAns(TreeNode* root, int targetSum, long long current_sum) {
        if(root == NULL) {
            return;
        }
        long long val = current_sum + root->val;
        if(val == targetSum ) {
            ans += 1;
        }
        if(mp.find(val - targetSum) != mp.end() && mp[val-targetSum]) {
            ans += mp[val-targetSum];
        }
        mp[val] += 1;
        getAns(root->left, targetSum, current_sum + root->val);
        getAns(root->right, targetSum, current_sum + root->val);
        mp[val] -= 1; 
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long current_sum = 0;
        getAns(root, targetSum, current_sum);
        return ans;
    }
};
