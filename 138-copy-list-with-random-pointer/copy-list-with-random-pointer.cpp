/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node *head1 = NULL, *copy = head, *dummy = new Node(-1), *res = dummy;
        while(copy) {
            Node *cur = copy, *nextNode = copy -> next;
            Node *nn = new Node(-1);
            nn -> val = cur -> val;
            cur -> next = nn;
            nn -> next = nextNode;
            copy = nextNode;
        }
        copy = head;
        while(copy) {
            Node *deepcopy = copy -> next, *nextNode = deepcopy -> next;
            if(copy -> random) deepcopy -> random = copy -> random -> next;
            else deepcopy -> random = NULL;
            copy = copy -> next -> next;
        }
        copy = head;
        while(copy) {
            dummy -> next = copy -> next;
            dummy = dummy -> next;
            copy -> next = copy -> next -> next;
            copy = copy -> next;
        }
        return res -> next;
    }
};