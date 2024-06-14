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
    int bestrob(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(root==NULL) return 0;
        if(dp.find(root)!=dp.end()) return dp[root];
        int nonpick=bestrob(root->left, dp)+bestrob(root->right, dp), val=root->val;
        TreeNode *r1=root->left, *r2=root->right;
        int rr1=0, rr2=0;
        if(r1!=NULL) rr1=bestrob(r1->left, dp)+bestrob(r1->right, dp);
        if(r2!=NULL) rr2=bestrob(r2->left, dp)+bestrob(r2->right, dp);
        int pick=val+rr1+rr2;
        return dp[root]=max(pick, nonpick);
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return bestrob(root, dp);
    }
};