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
    void mapNodes(TreeNode* parentNode, TreeNode *root, unordered_map<int, TreeNode*>& mp, unordered_map<int, TreeNode*>& parent) {
        if(root == NULL) return;
        mp[root -> val] = root;
        if(parentNode != NULL) parent[root -> val] = parentNode;
        mapNodes(root, root -> left, mp, parent);
        mapNodes(root, root -> right, mp, parent);
        return;
    }
    void deleteNode(TreeNode* root, unordered_map<int, TreeNode*>& parent) {
        if(root -> left != NULL) parent.erase(root -> left -> val);
        if(root -> right != NULL) parent.erase(root -> right -> val);
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int, TreeNode*> mp, parent;
        vector<TreeNode*> res;
        mapNodes(NULL, root, mp, parent);
        for(int i : to_delete) {
            if(parent.find(i) != parent.end()) {
                TreeNode* temp = parent[i];
                if(temp -> left && temp -> left -> val == i) {
                    deleteNode(temp -> left, parent);
                    temp -> left = NULL;
                }
                else if(temp -> right && temp -> right -> val == i) {
                    deleteNode(temp -> right, parent);
                    temp -> right = NULL;
                }
            } else deleteNode(mp[i], parent);
            mp.erase(i);
        }
        for(auto it : mp) if(parent.find(it.second -> val) == parent.end()) res.push_back(it.second);
        return res;
    }
};