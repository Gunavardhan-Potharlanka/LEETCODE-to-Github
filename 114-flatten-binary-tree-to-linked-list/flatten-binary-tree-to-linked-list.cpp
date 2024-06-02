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
    void traverse(TreeNode *root){
        if(root==NULL) return;
        if(root->left) traverse(root->left);
        if(root->right) traverse(root->right);
        TreeNode *temp=root->left;
        if(temp){
            TreeNode* temp1=temp;
            while(temp1->right) temp1=temp1->right;
            temp1->right=root->right;
            root->right=temp;
            root->left=NULL;
        }
        return;
    }
public:
    void flatten(TreeNode* root) {
        traverse(root);
    }
};