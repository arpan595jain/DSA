/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)return { };
        int max=INT_MIN,max1=0;
        int sum=0,count=1;
        vector<pair<int,int>>v;
        queue<TreeNode*>pq;
        pq.push(root);
        while(!pq.empty()){
            int n=pq.size();
            sum=0;
            for(int i=0;i<n;i++){
                TreeNode* root1=pq.front();
                pq.pop();
                if(root1->left!=NULL){
                    pq.push(root1->left);
                }
                if(root1->right!=NULL){
                    pq.push(root1->right);
                }
                sum+=root1->val;
            }
            if(sum>max){
                max=sum;
                max1=count;
            }
            count++;
        }
        return max1;
    }
};
