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
    int sumofrange(int l, int h, TreeNode* root){
        if(root==NULL) return 0;
        if((root->val>(l-1))&&(root->val<(h+1))) return (root->val)+sumofrange(l, h, root->left)+ sumofrange(l, h, root->right);
        else if((root->val)<l) return sumofrange(l, h, root->right);
        return sumofrange(l, h, root->left);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return sumofrange(low, high, root);
    }
};