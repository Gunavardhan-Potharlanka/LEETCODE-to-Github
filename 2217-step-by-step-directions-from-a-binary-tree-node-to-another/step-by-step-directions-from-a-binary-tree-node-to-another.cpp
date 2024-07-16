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
    string path1 = "", path2 = "";
    void recursion(TreeNode* root, int s, int d, string& path, bool b1, bool b2) {
        if(root == NULL) return;
        if(b1 && b2) return;
        if(root -> val == s) {
            b1 = true;
            path1 = path;}
        if(root -> val == d) {
            b2 = true;
            path2 = path;}
        if(root -> left) {
            path += 'L';
            recursion(root -> left, s, d, path, b1, b2);
            path.erase(path.size() - 1, 1);
        }
        if(root -> right) {
            path += 'R';
            recursion(root -> right, s, d, path, b1, b2);
            path.erase(path.size() - 1, 1);
        }
        return;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path = "S";
        recursion(root, startValue, destValue, path, false, false);
        int i = 0, j = i;
        string ans = "";
        while(i < path1.size() && i < path2.size() && path1[i] == path2[i]) i++;
        j = i;
        while(i++ < path1.size()) ans += 'U';
        return ans+path2.substr(j, path2.size() - j);
    }
};