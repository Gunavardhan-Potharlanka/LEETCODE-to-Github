/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* clone = new Node();
        clone -> val = node -> val;
        mp[node -> val] = clone;
        for(Node* nn : node -> neighbors) {
            if(mp.find(nn -> val) != mp.end())  (clone -> neighbors).push_back(mp[nn -> val]);
            else {
                Node *n = cloneGraph(nn);
                (clone -> neighbors).push_back(n);
                mp[nn -> val] = n;
            }
        }
        return clone;
    }
};