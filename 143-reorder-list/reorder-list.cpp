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
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        ListNode *temp1=head, *temp2=head;
        while(temp1 && temp2 && temp2->next){
            temp1=temp1->next;
            temp2=temp2->next->next;
        }
        ListNode* extra;
        if(temp2){
            extra=new ListNode(temp1->val);
            temp1=temp1->next;
        }
        ListNode *temp=new ListNode(head->val, head->next);
        head->next=NULL;
        stack<ListNode*> s;
        while(temp1){
            ListNode *nn=new ListNode(temp1->val);
            s.push(nn);
            temp1=temp1->next;
        }
        while(!s.empty()){
            if(head->next==NULL){
                head->next=s.top();
                s.pop();
                if(temp2 && s.empty()) head->next->next=extra;
            }
            else{
                ListNode* t1=head;
                while(t1->next) t1=t1->next;
                t1->next=new ListNode(temp->val, s.top());
                s.pop();
                if(temp2 && s.empty()) t1->next->next->next=extra;
            }
            temp=temp->next;
        }
    }
};