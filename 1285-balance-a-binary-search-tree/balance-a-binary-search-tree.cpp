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
    void traverse(TreeNode *root, vector<int>& nodes) {
        if(root == NULL) return;
        traverse(root->left, nodes);
        nodes.push_back(root -> val);
        traverse(root->right, nodes);
        return;
    }
    TreeNode *BBST(vector<int>& nodes, int start, int end) {
        if(start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode(nodes[mid]);
        node -> left = BBST(nodes, start, mid-1);
        node -> right = BBST(nodes, mid + 1, end);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        traverse(root, nodes);
        return BBST(nodes, 0, nodes.size() - 1);
    }
};