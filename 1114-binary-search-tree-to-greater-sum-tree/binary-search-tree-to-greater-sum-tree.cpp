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
    int MAX = 0;
    void recursion(TreeNode* root){
        if(root == NULL) return;
        if(root->right) recursion(root->right);
        MAX += root->val;
        root->val = MAX;
        if(root->left) recursion(root->left);
        return;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root == NULL) return root;
        recursion(root);
        return root;
    }
};