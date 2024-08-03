/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode *insert(ListNode *head, ListNode *tail) {
        if(head == NULL) return tail;
        ListNode *temp = head;
        while(temp -> next) temp = temp -> next;
        temp -> next = tail;
        return head;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL) return head;
        int n = 0;
        ListNode* copy = head;
        while(copy){
            n++;
            copy = copy->next;
        }
        k = (k % n);
        if(k == 0) return head;
        copy = head;
        ListNode* iterate = head;
        for(int i = 0 ; i < k ; i++) iterate = iterate -> next;
        while(iterate -> next) {
            copy = copy -> next;
            iterate = iterate -> next;
        }
        ListNode* h = copy -> next;
        copy -> next = NULL;
        h = insert(h, head);
        return h;
    }
};